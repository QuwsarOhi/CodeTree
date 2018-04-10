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


def Mid(l, r):
    k = r - l
    k = k / 2
    return k

def Cmp(elem):
    return elem[1]

def main():
    s = In()
    l = Fraction(0, 1)
    r = Fraction(1, 1)
    
    Ans = []
    for i, d in enumerate(s):
        #print("Present", l.numerator, l.denominator, r.numerator, r.denominator)
        if d == 'l':
            k = Mid(l, r)
            r -= k
            #print("K", k.numerator, k.denominator)
            Ans.append((i, r))
        else:
            k = Mid(l, r)
            l += k
            #print("K", k.numerator, k.denominator)
            Ans.append((i, l))
        #print("New", l.numerator, l.denominator, r.numerator, r.denominator)
    
    Ans.sort(key = Cmp)
    
    for x, y in Ans:
        Out(x+1)
    

    
if __name__ == '__main__':
    main()
