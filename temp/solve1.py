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

def main():
    x, y, k = map(int, In().split())
    
    ans = Fraction(x/y).limit_denominator(k)
    
    print(str(ans.numerator)+"/"+str(ans.denominator))
    
if __name__ == '__main__':
    main()
