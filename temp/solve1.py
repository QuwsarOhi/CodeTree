from sys import *
from bisect import *
from collections import *
from itertools import *
from fractions import *

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

def recur(pos, modVal):
    

def main():
    n = int(In())
    v = list(map(int, In().split()))
    v.sort()
    
    if(v[0] != 0):
        print("-1")
        return
    
    for val in reversed(v):
        print(val, end='')
    print()
    return
    
    
if __name__ == '__main__':
    main()
