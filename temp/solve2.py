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

def rmvToks(s):
    s = s.replace('-', '')
    s = s.replace(';', '')
    s = s.replace('_', '')
    s = s.lower()
    
    return s

def main():
    
    s = []
    for _ in range(3):
        s.append(rmvToks(input()))
    
    Set = set()
    for p in permutations(s):
        Set.add(''.join(p))
    
    n = int(input())
    
    for _ in range(n):
        st = rmvToks(input())
        
        if st in Set:
            print("ACC")
        else:
            print("WA")

    
    
if __name__ == '__main__':
    main()

