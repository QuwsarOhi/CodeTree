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

def main():
    #inputGrab()
    i = 0
    
    while(1):
        #a = int(Input[i])
        #b = int(Input[i+1])
        #m = int(Input[i+2])
        a, b, m = map(int, input().strip().split())
        
        if(a == 0 and b == 0 and m == 0):
            break
        
        print((a**b)%m)
        i = i + 3
    
if __name__ == '__main__':
    main()

