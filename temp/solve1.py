def all_pairs(lst):
    if len(lst) < 2:
        yield []
        return
    if len(lst) % 2 == 1:
        # Handle odd length list
        for i in range(len(lst)):
            for result in all_pairs(lst[:i] + lst[i+1:]):
                yield result
    else:
        a = lst[0]
        for i in range(1,len(lst)):
            pair = (a,lst[i])
            for rest in all_pairs(lst[1:i]+lst[i+1:]):
                yield [pair] + rest

cnt1=0
cnt2=0
for x in all_pairs([1,2,3,4,5,6]):
    paisi=0
    cnt1+=1
    print(x,end=" ")
    for i in range(len(x)):
        for j in range(len(x)):
            a=x[i][0]
            b=x[i][1]
            c=x[j][0]
            d=x[j][1]
            if(d>b and a>c):
                paisi=1
                break
        if(paisi==1):
            break
    if(paisi==1):
        cnt2+=1
        print("==>Invalid")
    else:
        print("==>Valid")
print(cnt1-cnt2)