import sys
from bisect import *

sys.stdin = open('in', 'r')
#sys.stdout = open('out', 'w')


def Out(x):
    sys.stdout.write(str(x) + '\n')

def In():
    return sys.stdin.readline().strip()

Input = []
def inputGrab():
    for line in sys.stdin:
        Input.extend(map(str, line.strip().split()))

def main():
    #inputGrab()
    
    Str = input()
    b, s, c = map(int, input().strip().split())
    pb, ps, pc = map(int, input().strip().split())
    money = int(input())
    
    #print(s, type(s))
    
    bCnt = Str.count("B")
    sCnt = Str.count("S")
    cCnt = Str.count("C")
    
    ans = min(b//bCnt, s//sCnt, c//cCnt)
    b -= ans*bCnt
    s -= ans*sCnt
    c -= ans*cCnt
    
    print(b, s, c)
    print(ans)
    
    
    
if __name__ == '__main__':
    main()
