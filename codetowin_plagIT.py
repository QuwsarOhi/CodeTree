import os
import json
from glob import glob

data = []

cppfiles = glob(os.path.join('codes', '*.cpp')) #glob('/content/data/*.cpp')
jsonfiles = glob(os.path.join('codes', '*json'))#glob('/content/data/*.json')
cppfiles.sort()
jsonfiles.sort()

for cpp, jsn in zip(cppfiles, jsonfiles):
    fname1 = (((str(cpp).split('/'))[-1]).split('.'))[0]
    fname2 = (((str(jsn).split('/'))[-1]).split('.'))[0]

    if fname1 != fname2:
        print('Error in file', fname1, fname2)
    
    with open(jsn) as f:
        jinfo = json.load(f)
    with open(cpp) as f:
        jinfo['code'] = f.read()
    data.append(jinfo)


#ratio = 0.8
skipped_problems = [1173, 1171, 1169]
count = 0

for i in range(len(data)):
    if data[i]['verdict'] != 'ACCEPTED': continue
    if data[i]['problem_id'] in skipped_problems: continue

    same = set()
    minmatch = 1
    for j in range(i+1, len(data)):
        if data[j]['problem_id'] in skipped_problems: continue
        if data[j]['verdict'] != 'ACCEPTED': continue
        if data[i]['problem_id'] != data[j]['problem_id']: continue
        if data[i]['user_id'] == data[j]['user_id']: continue
        #if data[i]['copied'] and data[j]['copied']: continue
        #if data[i]['contest_id'] == data[j]['contest_id']: continue

        filedir1 = os.path.join('codes', str(data[i]['id'])+".cpp")
        filedir2 = os.path.join('codes', str(data[j]['id'])+".cpp")

        os.system(f"plagIT.py -f {filedir1} {filedir2} -t 0.9 -l {count}")
        count += 1