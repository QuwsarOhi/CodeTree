# Codeforces
# C. Hamburgers
# http://codeforces.com/contest/371/problem/C

import sys
from bisect import *

INF = 1e9
Input = []
MOD = 1000000007

#sys.stdin = open('in', 'r')
#sys.stdout = open('out', 'w')

def Out(x):
    sys.stdout.write(str(x) + '\n')
    
def In():
    return sys.stdin.readline().strip()

def inputGrab():
    for line in sys.stdin:
        Input.extend(map(str, line.strip().split()))

############################################################

Nb = 0
Ns = 0
Nc = 0
bCnt = 0
sCnt = 0
cCnt = 0
burgerCost = 0
sausageCost = 0
cheeseCost = 0
budget = 0

def canTake(val):
    cost = max(0, burgerCost*((val*bCnt)-Nb))
    cost += max(0, sausageCost*((val*sCnt)-Ns))
    cost += max(0, cheeseCost*((val*cCnt)-Nc))
    
    #print(val, cost)
    if cost <= budget:
        return 1
    return 0
    

def binarySearch(lo, hi):
    ans = int()
    while lo <= hi:
        mid = (lo+hi)//2
        
        if canTake(mid):
            ans = max(ans, mid)
            lo = mid+1
        else:
            hi = mid-1
    return ans
    
        

def main():
    Str = input()
    
    global Nb
    global Ns
    global Nc
    global burgerCost
    global sausageCost
    global cheeseCost
    global budget
    global bCnt
    global sCnt
    global cCnt
    
    Nb, Ns, Nc = map(int, input().strip().split())
    burgerCost, sausageCost, cheeseCost = map(int, input().strip().split())
    budget = int(input())
    
    bCnt = Str.count('B')
    sCnt = Str.count('S')
    cCnt = Str.count('C')
    
    print(binarySearch(0, int(1e17)))
    
    
if __name__ == '__main__':
    main()
