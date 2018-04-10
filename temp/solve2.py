from sys import *
from bisect import *
from collections import *
from itertools import *
from fractions import *
from datetime import *
from math import *
from random import *


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
    n, k = map(int, input().split())
    cnt = 0
    
    for _ in range(n):
        x = int(input())
        if x%k == 0:
            cnt += 1
    
    print(cnt)


if __name__ == '__main__':
    main()
