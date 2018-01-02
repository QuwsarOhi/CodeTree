from sys import *
from bisect import *
from collections import *

INF = 1e9
Input = []
MOD = 1000000007

#stdin = open('in', 'r')
#stdout = open('out', 'w')

def Out(x):
    stdout.write(str(x) + '\n')

def In():
    return stdin.readline().strip()

def inputGrab():
    for line in stdin:
        Input.extend(map(str, line.strip().split()))

############################################################

def main():
    n, k = map(int, In().split())
    v = map(int, In().split())
    
    v = list(v)
    
    Max = -1
    Min = 110
    for i in v:
        Min = min(i, Min)
        Max = max(i, Max)
    
    pile = [[] for i in range(110)]
    if abs(Max-Min) > k:
        print("NO")
    else:
        print("YES")
        Color = 1
        changed = True
        while changed:
            Min = 110
            changed = False
            for i in range(len(v)):
                if v[i] != 0:
                    pile[i].append(Color)
                    v[i] -= 1
                    Min = min(Min, v[i])
                    changed = True
            #if Min == 0:
            Color += 1
            if Color > k:
                Color = 1
        
        for i in range(n):
            for y in pile[i]:
                print(y, end = " ")
            print()
        
    
if __name__ == '__main__':
    main()
