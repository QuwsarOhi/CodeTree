from sys import *
from bisect import *
from collections import *
from itertools import *
from fractions import *
from datetime import *
from math import *

Input = []

#stdin = open('in', 'r')
#stdout = open('out', 'w')

## for i, val in enumerate(array, start_i_value)

def Out(x):
    stdout.write(str(x) + '\n')

def In():
    return stdin.readline().strip()

def inputGrab():
    for line in stdin:
        Input.extend(map(str, line.strip().split()))
'''--------------------------------------------------------------------------------'''

def dist(x1, x2, y2):
    x0 = x1-x2
    x0 = x0 * x0
    return sqrt(x0 + y2)

def main():
    n, vb, vs = map(int, In().split())
    
    d = list(map(int, In().split()))
    x, y = map(int, In().split())
    
    best = 100000000.0
    ans = 100000000
    
    for i in range(1, n):
        tmp = (d[i] / vs) +dist(d[i], x, y)*vs
        
        #print("At", i, tmp)
        
        if(tmp < best):
            #print("Best", tmp, i)
            ans = i
            best = tmp
        
        
    print(ans+1)
    
    
if __name__ == '__main__':
    main()
