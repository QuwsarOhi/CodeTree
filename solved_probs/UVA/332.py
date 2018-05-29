# UVa
# 332 - Rational Numbers from Repeating Fractions

from sys import *
from bisect import *
from collections import *
from itertools import *
from fractions import *
from datetime import *
from math import *
from decimal import *

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
    cc = 1
    inputGrab()
    
    for i in range(0, len(Input)-1, 2):
        k = int(Input[i])
        ss = Input[i+1]
        d = Decimal(ss)
        l = abs(d.as_tuple()[2])
        
        lim = int(ss[2:])
        
        #print(d, l, lim, 10**l - 10**k)

        a = ceil(((10**l) * d) - (10**(l-k)) * d)
        b = 10**l - 10**(l-k)
        
        x = gcd(a, b)
        if x != 0:
            a = a//x
            b = b//x
        if x == 0:
            f = Fraction(d)
            print("Case %d: %s/%s"%(cc, f.numerator, f.denominator))
        else:
            print("Case %d: %d/%d"%(cc, a, b))
        cc += 1
        

if __name__ == '__main__':
    main()
