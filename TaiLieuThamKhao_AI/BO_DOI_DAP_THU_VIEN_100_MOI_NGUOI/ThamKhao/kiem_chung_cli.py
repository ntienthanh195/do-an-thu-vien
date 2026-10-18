from pathlib import Path
import json,hashlib,subprocess,re,sys
sys.stdout.reconfigure(encoding='utf-8')
import argparse,tempfile
parser=argparse.ArgumentParser(description='24 ca CLI tổng hợp; cần exe tự build từ nguồn kèm gói.')
parser.add_argument('--exe',required=True)
parser.add_argument('--report',required=True,help='Đường báo cáo mới, không ghi đè báo cáo đã bàn giao')
args=parser.parse_args()
EXE=Path(args.exe).resolve()
REPORT=Path(args.report).resolve()
assert not REPORT.exists(), 'Chọn báo cáo mới để giữ bằng chứng cũ'
temp_owner=tempfile.TemporaryDirectory(prefix='thu-vien-325-')
WORK=Path(temp_owner.name)
OUT=Path(__file__).resolve().parents[1]
FIX=WORK/'fixtures';FIX.mkdir(exist_ok=True)
results=[]
def book(i='X',name='Sach X',copies=None,genre='CNTT'):
    return i,name,copies if copies is not None else [('X#1',0),('X#2',0)],genre
def reader(i=1,name='An',status=1,hist=None,ho='Nguyen'):
    return i,ho,name,status,hist or []
def active(c,d='14/10/2026'): return c,d,'0/0/0',0
def closed(c,a='01/10/2026',b='02/10/2026',status=1):return c,a,b,status
def library(books,readers,maxid=20):
    lines=[str(max([maxid]+[r[0] for r in readers])),str(len(books))]
    for isbn,name,copies,genre in books:
        lines += [f'{isbn}|{name}|100|Tac gia|2024|{genre}|{len(copies)}']
        lines += [f'{code}|{s}|Ke 1' for code,s in copies]
    lines += [str(len(readers))]
    for card,ho,name,status,hist in readers:
        lines += [f'{card}|{ho}|{name}|Nam|{status}|{len(hist)}']
        lines += ['|'.join(map(str,h)) for h in hist]
    return '\n'.join(lines)+'\n'
def state(path):
    l=path.read_text(encoding='utf-8').splitlines();p=2;b={};c={};r={}
    for _ in range(int(l[1])):
        f=l[p].split('|');p+=1;b[f[0]]=f[:6]
        for _ in range(int(f[6])):
            x=l[p].split('|');p+=1;c[x[0]]=(int(x[1]),f[0],x[2])
    n=int(l[p]);p+=1
    for _ in range(n):
        f=l[p].split('|');p+=1;hs=[]
        for _ in range(int(f[5])):hs.append(l[p].split('|'));p+=1
        r[int(f[0])]={'name':f[2],'status':int(f[4]),'history':hs}
    assert p==len(l)
    return {'max':int(l[0]),'books':b,'copies':c,'readers':r}
def execute(args,commands=None):
    return subprocess.run([str(EXE),*args],input=None if commands is None else ('\n'.join(commands)+'\n').encode(),capture_output=True,timeout=25)
def fixture(name,data,valid=True):
    p=FIX/(name+'.txt');p.write_text(data,encoding='utf-8')
    check=execute(['--check',str(p)])
    assert (check.returncode==0)==valid,(name,check.stderr.decode())
    return p
def run(name,ids,data,commands,expect,date='16/10/2026'):
    path=fixture(name,data);before=path.read_bytes();p=execute(['--plain','--date',date,'--data',str(path)],commands)
    out=p.stdout.decode('utf-8').replace('\r\n','\n');err=p.stderr.decode('utf-8');assert p.returncode==0,(name,err)
    now=state(path);assert expect(out,now,path,before),(name,out,now)
    assert execute(['--check',str(path)]).returncode==0
    results.append({'case':name,'question_ids':ids,'status':'PASS','mode':'CLI --plain + saved-state/byte assertions','stdout':out,'stderr':err})

run('sequential_same_copy',['TV01'],library([book()],[reader(1),reader(2)]),['6','1','X#1','6','2','X#1','0'],
    lambda o,s,p,b:o.count('Giao dich thanh cong')==1 and len(s['readers'][1]['history'])==1 and not s['readers'][2]['history'])
run('locked_full_overdue_precedence',['TV51'],library([book(copies=[('X#1',1),('X#2',1),('X#3',1),('X#4',0)])],[reader(status=0,hist=[active('X#1','01/10/2026'),active('X#2'),active('X#3')])]),['6','1','X#4','0'],
    lambda o,s,p,b:'The doc gia dang bi khoa.' in o and len(s['readers'][1]['history'])==3)
run('full_before_overdue',['TV51'],library([book(copies=[('X#1',1),('X#2',1),('X#3',1),('X#4',0)])],[reader(hist=[active('X#1','01/10/2026'),active('X#2'),active('X#3')])]),['6','1','X#4','0'],
    lambda o,s,p,b:'toi da 3 cuon' in o and s['copies']['X#4'][0]==0)
for day,ok in [('15/10/2026',True),('16/10/2026',False)]:
    run('seven_eight_'+day[:2],['TV04'],library([book(copies=[('X#1',1),('X#2',0)])],[reader(hist=[active('X#1','08/10/2026')])]),['6','1','X#2','0'],
        lambda o,s,p,b,ok=ok:(s['copies']['X#2'][0]==1)==ok,date=day)
run('return_then_other_borrow_old_return',['TV05'],library([book(copies=[('X#1',1)])],[reader(1,hist=[active('X#1')]),reader(2)]),['7','1','1','X#1','6','2','X#1','7','1','1','X#1','0'],
    lambda o,s,p,b:o.count('Giao dich thanh cong')==2 and s['readers'][1]['history'][0][-1]=='1' and s['readers'][2]['history'][0][-1]=='0')
run('lost_then_return_other',['TV06','TH247'],library([book(copies=[('X#1',1),('X#2',1)])],[reader(hist=[active('X#1'),active('X#2')])]),['7','1','2','X#1','7','1','1','X#2','1','2','1','Nguyen','An','Nam','1','0'],
    lambda o,s,p,b:s['readers'][1]['status']==0 and [h[-1] for h in s['readers'][1]['history']]==['2','1'] and s['copies']['X#1'][0]==2)
run('two_identical_day_loans',['TH241'],library([book(copies=[('X#1',0)])],[reader()]),['6','1','X#1','7','1','1','X#1','6','1','X#1','7','1','1','X#1','10','0'],
    lambda o,s,p,b:len(s['readers'][1]['history'])==2 and s['readers'][1]['history'][0]==s['readers'][1]['history'][1] and '2 luot' in o)
run('lost_no_reopen',['TV48'],library([book(copies=[('X#1',1)])],[reader(hist=[active('X#1')])]),['7','1','2','X#1','7','1','1','X#1','0'],
    lambda o,s,p,b:o.count('Giao dich thanh cong')==1 and s['readers'][1]['history'][0][-1]=='2')
run('book_and_copies_retry',['TH226'],library([],[]),['3','1','A','Ten A','100','Tac gia','2024','CNTT','0','3','1','A','Ten A','100','Tac gia','2024','CNTT','3','2','A','2','Ke 1','Ke 1','0'],
    lambda o,s,p,b:len(s['books'])==1 and set(s['copies'])=={'A#1','A#2'})
run('new_legacy_distinct',['TH252'],library([book('A','Sach A',[('S001',1),('A#1',1)])],[reader(1,hist=[active('S001')]),reader(2,hist=[active('A#1')])]),['3','2','A','1','Ke 2','10','0'],
    lambda o,s,p,b:'A#2' in s['copies'] and '2 luot' in o)
books=[book(chr(65+i),'Same',[(chr(65+i)+'#1',0)]) for i in range(12)]
readers=[reader(i+1,hist=[closed(chr(65+i)+'#1')]) for i in range(12)]
run('top_twelve_ties',['TH14','TH74'],library(books,readers),['10','0'],
    lambda o,s,p,b:re.findall(r'^\d+ \| ([A-L]) \| Same \| 1 luot$',o,re.M)==list('ABCDEFGHIJ'))
run('overdue_partial_return',['TH61'],library([book(copies=[('X#1',1),('X#2',1),('X#3',1),('X#4',0)])],[reader(20,hist=[active('X#1','01/10/2026'),active('X#2','08/10/2026')]),reader(10,hist=[active('X#3','04/10/2026')])]),['7','20','1','X#1','9','6','20','X#4','0'],
    lambda o,s,p,b:re.findall(r'^(\d+) \|.*\| Qua han:',o,re.M)==['10','20'] and s['copies']['X#4'][0]==0)
run('reader_ties_and_readonly',['TN05'],library([],[reader(30,'AN',ho='Tran'),reader(10,'an',ho='Tran'),reader(20,'An',ho='Le')]),['2','2','13','THOAT'],
    lambda o,s,p,b:re.findall(r'^(\d+) \|(?: Tran| Le) \|',o,re.M)==['20','10','30'] and p.read_bytes()==b)
run('partial_book_cancel',['TH15'],library([],[]),['3','1','A','Ten A','100','TG','2024','CNTT','3','Ke1','/huy','0'],
    lambda o,s,p,b:len(s['books'])==1 and list(s['copies'])==['A#1'])
run('eof_unsaved',['TN56'],library([],[]),['1','1','Nguyen','An','Nam','1','1','Nguyen'],
    lambda o,s,p,b:not s['readers'] and p.read_bytes()==b)
run('delete_keep_highwater',['TV08'],library([],[reader(20)]),['1','3','20','1','1','Nguyen','Moi','Nam','0'],
    lambda o,s,p,b:s['max']==21 and set(s['readers'])=={21})
run('leap_seven',['TV04','TV73'],library([book(copies=[('X#1',1),('X#2',0)])],[reader(hist=[active('X#1','25/02/2024')])]),['6','1','X#2','0'],
    lambda o,s,p,b:s['copies']['X#2'][0]==1,date='03/03/2024')
run('leap_eight',['TV04','TV73'],library([book(copies=[('X#1',1),('X#2',0)])],[reader(hist=[active('X#1','25/02/2024')])]),['6','1','X#2','0'],
    lambda o,s,p,b:s['copies']['X#2'][0]==0,date='04/03/2024')
for label,hist,valid in [
    ('four_overlap',[closed('X#'+str(i),'01/10/2026','10/10/2026') for i in range(1,5)],False),
    ('four_same_day',[closed('X#'+str(i),'10/10/2026','10/10/2026') for i in range(1,5)],True)]:
    path=fixture(label,library([book(copies=[('X#'+str(i),0) for i in range(1,5)])],[reader(hist=hist)]),valid)
    results.append({'case':label,'question_ids':['TV11'],'status':'PASS','mode':'--check expected accept/reject','accepted':valid})
base=fixture('load_current',library([],[]));bad=FIX/'broken.txt';bad.write_text('20\n1\nX|Name|100|TG|2024|CNTT|2\nX#1|0|Ke1\n',encoding='utf-8')
before=base.read_bytes();p=execute(['--plain','--data',str(base),'--date','16/10/2026'],['1','1','Nguyen','Moi','Nam','11',str(bad),'NAP','0'])
assert p.returncode==0 and set(state(base)['readers'])=={21}
results.append({'case':'load_failure_keeps_ram','question_ids':['GH03','TH209'],'status':'PASS','mode':'truncated file, CLI load failure then save RAM','stdout':p.stdout.decode()})
b=fixture('load_target',library([],[reader(7)]));a=fixture('load_origin',library([],[]));original=a.read_bytes()
p=execute(['--plain','--data',str(a),'--date','16/10/2026'],['1','1','Nguyen','Moi','Nam','11',str(b),'NAP','0'])
assert p.returncode==0 and a.read_bytes()==original and set(state(b)['readers'])=={7}
results.append({'case':'load_success_switches_destination','question_ids':['TN73'],'status':'PASS','mode':'CLI load then save destination','stdout':p.stdout.decode()})
invalid=fixture('invalid_state',library([book(copies=[('X#1',0)])],[reader(hist=[active('X#1')])]),False)
before=invalid.read_bytes();p=execute(['--plain','--data',str(invalid)],['0'])
assert p.returncode==2 and invalid.read_bytes()==before
results.append({'case':'startup_invalid_no_overwrite','question_ids':['TN75','GH04'],'status':'PASS','mode':'startup failure code2 and original file bytes'})
report={'date':__import__('datetime').date.today().isoformat(),'case_count':len(results),'cases':results,'executable_help':execute(['--help']).stdout.decode(),'exe_sha256':hashlib.sha256(EXE.read_bytes()).hexdigest(),
        'source_sha256':{p.name:hashlib.sha256(p.read_bytes()).hexdigest() for p in (OUT/'ThamKhao/MaNguon').glob('*')},
        'limits':'Fresh CLI/plain tests only. No physical TUI/IME/mouse QA, allocation fault injection, power-loss, concurrency load, million-record benchmark or learner assessment.'}
REPORT.write_text(json.dumps(report,ensure_ascii=False,indent=2)+'\n',encoding='utf-8')
print(f'PASS {len(results)} fresh scenario cases')
