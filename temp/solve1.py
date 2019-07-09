from sys import stdin, stdout
from math import *
#from fractions import *
#from bisect import *
#from collections import deque
 
class scanner:
    inputIDX = 0
    Input = []
    
    # File Read/Write
    stdin = stdin
    #stdin = open('in', 'r')
    #stdout = open('out', 'w')
    
    def __init__(self):
        self.inputGrab()
 
    def Out(self, x, end="\n"):
        stdout.write(str(x) + end)
 
    def In(self):
        return stdin.readline().strip()
 
    def inputGrab(self):
        for line in self.stdin:
            self.Input.extend(map(str, line.strip().split()))
 
    def hasNext(self):
        return True if self.inputIDX < len(self.Input) else False
 
    def nextInt(self):
        self.inputIDX += 1
        return int(self.Input[self.inputIDX-1])
 
    def nextString(self):
        self.inputIDX += 1
        return self.Input[self.inputIDX-1]
 
'''--------------------------------------------------------------------------------'''
 
n = 0
total = 0
a = []

def update(pos, v):
    for 
 
def T(s, t):
    tmp = 0
    t += 1
    for i in range(s, t):
        tmp += a[i]
    return tmp
 
 
def cal():
    global n
 
    l = 0
    r = n-1
    ans = n+3
    mini = total
 
    while l <= r:
        mid = (l+r)//2
        x = T(0, mid)
        #y = T(mid+1, n-1)
        y = total - x
        dist = abs(x-y)
 
        if dist < mini:
            mini = dist
            ans = mid
        elif dist == mini:
            ans = min(ans, mid)
 
        if x < y:
            l = mid+1
        else:
            r = mid-1
 
    return ans+1

base = 1000000000000000000 
 
def main():
    sc = scanner()
 
    global a
    global n
    global total
 
    n = sc.nextInt()
    m = sc.nextInt()
    total = 0;
 
    for i in range(n):
        x = sc.nextInt()
        #print(x, log(x, base))
        x = log(x, base)
        a.append(x)
        total = total + x
 
    #print("DONE")
    while m != 0:
        typ = sc.nextInt()
 
        if typ == 1:
            pos = sc.nextInt() - 1
            tmp = sc.nextInt()
            tmp = log(tmp, base)
            a[pos] = a[pos] + tmp
            total = total + tmp
        else:
            print(cal())
 
        m -= 1
 
 
 
main()