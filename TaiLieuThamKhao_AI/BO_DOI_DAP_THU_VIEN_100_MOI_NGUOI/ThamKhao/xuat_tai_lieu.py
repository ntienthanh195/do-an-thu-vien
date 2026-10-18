from pathlib import Path
import json,re
REF=Path(__file__).resolve().parent;OUT=REF.parent
NAMES={'thai':'Thái','thanh':'Thành','tan':'Tấn','chung':'Cả nhóm'}
def render():
    a=json.loads((REF/'du_lieu_325.json').read_text(encoding='utf-8'))
    meta=json.loads((REF/'bien_tap_20261018.json').read_text(encoding='utf-8'))
    byid={q['id']:q for q in a}
    first=['TV01','TV03','TV04','TV05','TV06','TV07','TV10','TV11','TH02','TH06','TH14','TH61','TN01','TN03','TN71','TN100','GH02','GH03','GH05','CH05']
    qmd=[(REF/'mo_dau_cau_hoi.txt').read_text(encoding='utf-8'),'<a id="on-truoc"></a>','## 20 câu ôn trước','']
    qmd += [f"- [{i} — {byid[i]['title']}](#{i})" for i in first]
    amd=['# Đáp án — 325 câu đối đáp Thư viện','','**Thái 100 · Thành 100 · Tấn 100 · Cả nhóm 25.** [Câu hỏi](01_CAU_HOI.md) · [Báo cáo kiểm tra](ThamKhao/BAO_CAO_KIEM_TRA.md).','',
    'Bản chỉnh nội dung 18/10/2026. “Truy vết/đề xuất” không phải kết quả đã chạy. [25 ca ngày17/10](ThamKhao/KIEM_CHUNG_RUNTIME.md) là bằng chứng lịch sử, không chạy lại trong đợt này. [18 lượt kiểm mới](ThamKhao/KIEM_DINH_20261018.md) gồm16 lượt assertion và2 timeout có chủ đích. Mỗi liên kết dưới chỉ xác nhận phạm vi ca, không chứng nhận toàn câu/câu phụ hay phương án chưa cài.','',
    'Quy ước D/C/R/H/h/L, giới hạn, cấu trúc bắt buộc và giả định G01–G12 nằm ở đầu file câu hỏi. Đáp án là căn cứ phản biện, không phải lời nói học thuộc hoặc bằng chứng người học đã tự làm.','']
    def refs(q):
        return '; '.join(f"[{s['file']}](ThamKhao/MaNguon/{s['file']}) — `{s['symbol']}`, dòng "+', '.join(map(str,s['lines'])) for s in q['source'])
    for g,name in NAMES.items():
        rows=[q for q in a if q['group']==g]
        qmd += ['',f'<a id="{g}"></a>',f'## {name} — {len(rows)} câu','']
        amd += ['',f'<a id="{g}"></a>',f'## {name} — {len(rows)} đáp án','']
        for n,q in enumerate(rows,1):
            i=q['id'];qmd += [f'<a id="{i}"></a>',f"### {n:03}. {i} — {q['title']}",'',f"**Phụ trách:** {name} · **Ưu tiên:** {q['priority']} · **Phạm vi:** {q['scope']}.",'',f"**Trọng tâm:** {q['topic']}.",'',f"**Chỉ vào code:** {refs(q)}.",'',f"**Câu chính:** {q['question']}",'']
            for k,f in enumerate(q['followups'],1):qmd += [f"**Câu phụ {k}:** {f['question']}",'']
            qmd += [f'[Mở đáp án {i}](02_DAP_AN.md#{i}) · [Về đầu phần](#{g})','']
            amd += [f'<a id="{i}"></a>',f"### {i} — {q['title']}",'',f"**{name} · {q['priority']} · {q['scope']}**. [Đọc lại câu hỏi](01_CAU_HOI.md#{i}).",'','**Trả lời ngắn:** '+q['answer'][0],'','**Giải thích và bảo vệ cách làm:**','']
            for s in q['answer'][1:]:amd += [s,'']
            for k,f in enumerate(q['followups'],1):amd += [f"**Đáp câu phụ {k}:** {f['answer']}",'']
            amd += ['**Sai lầm dễ mắc:** '+q['mistake'],'','**Cách kiểm chứng:** '+q['verify'],'']
            if q.get('runtime_cases_20261018'):amd += ['**Kiểm mới 18/10:** '+', '.join(f'[{c}](ThamKhao/KIEM_DINH_20261018.md#{c})' for c in q['runtime_cases_20261018'])+'. Chỉ các assertion/quan sát nêu trong ca.','']
            if q.get('runtime_cases'):amd += ['**Ca liên quan đã chạy 17/10 (không tái chạy đợt này):** '+', '.join(f'[{c}](ThamKhao/KIEM_CHUNG_RUNTIME.md#{c})' for c in q['runtime_cases'])+'.','']
            if not q.get('runtime_cases_20261018') and not q.get('runtime_cases'):amd += ['**Mức bằng chứng:** đọc mã và truy vết; chưa chạy riêng toàn tình huống/câu phụ.','']
            amd += ['**Nguồn đối chiếu:** '+refs(q)+'.','']
    # Redirect old IDs without creating extra question headings/counts.
    for arr,other in [(qmd,'01_CAU_HOI.md'),(amd,'02_DAP_AN.md')]:
        arr += ['','## Mốc ID đã gộp','', 'Các mục sau chỉ điều hướng, không phải câu riêng.','']
        for m in meta['mapping']:
            arr += [f'<a id="{m["retired_id"]}"></a>',f"{m['retired_id']} đã gộp vào [{m['merged_into']}](#{m['merged_into']}); vị trí bổ sung dùng ID mới [{m['new_slot_id']}](#{m['new_slot_id']}).",'']
    return {'01_CAU_HOI.md':'\n'.join(qmd)+'\n','02_DAP_AN.md':'\n'.join(amd)+'\n'}
if __name__=='__main__':
    for name,t in render().items():(OUT/name).write_text(t,encoding='utf-8')
    print('Exported 325 from canonical JSON; run release validation before packaging.')
