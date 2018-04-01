from sys import *
from bisect import *
from collections import *
from itertools import *
from fractions import *
from datetime import *
from math import *
from statistics import *

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

def main():
    n = int(In())
    
    v = []
    for _ in range(n):
        v.append(int(In()))
        
    Mode = mode(v)
    cnt = 0
    From = 0
    To = 0
    
    for i, val in enumerate(v, 1):
        if val != Mode:
            if val < Mode:
                From = i
            else:
                To = i
            cnt += 1
    
    if cnt == 2:
        Amount = abs(v[From-1] - v[To-1])
        if Amount%2 != 0:
            cnt += 1
    
    if cnt > 2:
        print("Unrecoverable configuration.")
    elif cnt == 0:
        print("Exemplary pages.")
    else:
        print("%d ml. from cup #%d to cup #%d." %(Amount//2, From, To))
    
    

if __name__ == '__main__':
    main()
