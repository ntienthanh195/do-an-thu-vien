from pathlib import Path
import json,hashlib,shutil,sys,argparse,tempfile
sys.stdout.reconfigure(encoding='utf-8')
parser=argparse.ArgumentParser(description='Rerun 18 semantic checks in isolated copies; requires g++ C++17 on Windows.')
parser.add_argument('--report',required=True)
args=parser.parse_args();REPORT=Path(args.report).resolve()
assert not REPORT.exists(), 'Report must be new; preserve prior evidence'
REF=Path(__file__).resolve().parent
owner=tempfile.TemporaryDirectory(prefix='library-semantic-')
WORK=Path(owner.name)
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def save(p,v):p.write_text(json.dumps(v,ensure_ascii=False,indent=2)+'\n',encoding='utf-8')
import subprocess,time,datetime
BUILD=WORK/'Runtime';BUILD.mkdir(exist_ok=True)
SRC=REF/'MaNguon'
def run(args,**kw):return subprocess.run([str(x) for x in args],capture_output=True,**kw)
CPP=REF/'kiem_dinh_tinh_huong.cpp'
variants={}
for variant in ['original','commit_before_tail','reset_by_day']:
    dest=BUILD/variant;dest.mkdir(exist_ok=True)
    for p in SRC.iterdir():shutil.copy2(p,dest/p.name)
    if variant=='commit_before_tail':
        p=dest/'06_NghiepVuTongHop.cpp';s=p.read_text(encoding='utf-8')
        old='MuonTra** tail=&dg.dsMuonTra;';assert s.count(old)==1
        s=s.replace(old,'cuon->trangThai=SACH_DANG_MUON;\n        '+old)
        old='*tail=moi.release(); cuon->trangThai=SACH_DANG_MUON;';assert s.count(old)==1
        p.write_text(s.replace(old,'*tail=moi.release();'),encoding='utf-8')
    if variant=='reset_by_day':
        p=dest/'07_LuuDocFile.cpp';s=p.read_text(encoding='utf-8')
        s=s.replace('int reader=0,held=0;','int reader=0,held=0,lastDay=-1;')
        old='if(moc[i].maThe!=reader) {reader=moc[i].maThe;held=0;}'
        assert s.count(old)==1
        s=s.replace(old,'if(moc[i].maThe!=reader || moc[i].ngay!=lastDay) {reader=moc[i].maThe;lastDay=moc[i].ngay;held=0;}')
        p.write_text(s,encoding='utf-8')
    exe=dest/'cases.exe'
    args=['g++','-std=c++17','-O2','-Wall','-Wextra','-pedantic','-DTHUVIEN_TEST']
    if variant=='reset_by_day':args+=['-DDAY_RESET_MUTANT']
    args+=['-I',dest,CPP,*sorted(dest.glob('*.cpp')),'-lshell32','-o',exe]
    result=run(args);assert result.returncode==0,result.stderr.decode(errors='replace')
    variants[variant]={'exe':str(exe),'sha256':sha(exe),'diagnostics':result.stderr.decode(errors='replace'),'source_hashes':{p.name:sha(p) for p in dest.iterdir() if p.suffix in ['.cpp','.h']}}
    print('Built',variant,flush=True)
cases=[]
spec=[('original',s) for s in ['foreign_cycle','sort_permutation','top_late','top_ties','code509','code510','publication_date','sweep_valid','sweep_four','bst_bounds','partial_batch','four_open','top_missing']]
spec += [('reset_by_day','sweep_valid'),('reset_by_day','sweep_four'),('commit_before_tail','foreign_cycle'),('original','own_cycle'),('commit_before_tail','own_cycle')]
for variant,case in spec:
    start=time.monotonic();args=[variants[variant]['exe'],case]
    if case=='own_cycle':
        try:
            r=run(args,timeout=2)
            raise AssertionError('Cycle unexpectedly ended: '+repr(r.stdout))
        except subprocess.TimeoutExpired as ex:
            stdout=(ex.stdout or b'').decode(errors='replace');assert 'BEFORE_MUON copy=0' in stdout,stdout
            rec={'variant':variant,'case':case,'status':'EXPECTED_TIMEOUT','stdout':stdout,'seconds_limit':2,'meaning':'Không kết thúc trong 2s; nguyên nhân không tới commit được xác định từ thứ tự helper trong mã, không từ timeout đơn lẻ.'}
    else:
        r=run(args,timeout=15);assert r.returncode==0,(variant,case,r.stdout,r.stderr)
        assert ('PASS '+case) in r.stdout.decode()
        rec={'variant':variant,'case':case,'status':'PASS','stdout':r.stdout.decode(),'stderr':r.stderr.decode()}
    rec['elapsed_seconds']=round(time.monotonic()-start,3);cases.append(rec);print(variant,case,rec['status'],flush=True)
report={'date':datetime.datetime.now().isoformat(),'compiler':run(['g++','--version']).stdout.decode().splitlines()[0],'harness_sha256':sha(CPP),'runner_sha256':sha(Path(__file__)),'variants':variants,'cases':cases,
        'limits':'16 lượt chạy assertion + 2 tiến trình timeout có chủ đích; không phải 18 câu độc lập hay chứng nhận 325 câu. Hai biến thể chỉ sửa bản sao trong Runtime. Không QA TUI, lỗi cấp phát, tải triệu, mất điện hoặc concurrency.'}
save(REPORT,report)
print('Completed',len(cases),'runs')
