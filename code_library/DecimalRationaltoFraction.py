# Rational/Decimal to Fraction

# Convert any rational to fractions
# Example : 
# 0.71428, here 71428 (6 in size) repeats, ans : 5/7
# input stream : 
# 6 0.714285   : 5/7
# 2 0.09       : 1/11
# 2 0.318      : 7/22
# Equation : (10^(k+j))*x - (10^k)*x
# k = repeating value length (in the decimals)
# j = non repeating value length (in the decimals)
# if k = is zero, then the number is in decimal, not in rational

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
#---------------------------------------------------------------------------------------#

def main():
    inputGrab()
    k = int(Input[0])
    d = Decimal(Input[1])                   # Decimal does accurate calculation
    l = abs(d.as_tuple()[2])                # length of decimal values
    lim = int(Input[1][2:])
    a = ceil(((10**l) * d) - (10**(l-k)) * d)
    b = 10**l - 10**(l-k)

    x = gcd(a, b)
    if x != 0:
        a = a//x
        b = b//x
    if x == 0:
        f = Fraction(d)                     # Convert any normal decimal value to fraction
        print("%s/%s"%(f.numerator, f.denominator))
    else:
        print("%d/%d"%(a, b))
        
if __name__ == '__main__':
    main()
