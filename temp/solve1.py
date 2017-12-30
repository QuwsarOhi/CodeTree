import sys

#sys.stdin = open('in', 'r')
#sys.stdout = open('out', 'w')

def Out(x):
    sys.stdout.write(str(x) + '\n')

def In():
    return sys.stdin.readline().strip()
'''
5
4 1
4 2
5 1
2 2
6 1'''

def main():
    n = int(In())
    arr = []
    for i in range(n):
        x, y = In().split()
        arr.append((x, y))
    
    
    cnt = 0
    for i in range(len(arr)-1):
        inc = 1
        for j in range(i+1, len(arr)):
            if arr[i] != arr[j]:
                print("ok")
                if arr[i][0] == arr[j][0] or arr[i][1] == arr[j][1]:
                    inc = 0
                    print("inc to zero", arr[i], arr[j])
        if inc:
            cnt += 1
    
    print(cnt)
    
if __name__ == '__main__':
    main()
