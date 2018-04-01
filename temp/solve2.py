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
stdout = open('out', 'w')

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
    for _ in range(20):
        a = randint(0, 30)
        b = randint(0, 30)
        c = randint(1, 30)
    
        Out(" ".join(list(map(str, [a, b, c]))))



if __name__ == '__main__':
    main()
