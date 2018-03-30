from sys import *
from bisect import *
from collections import *
from itertools import *
from fractions import *
from datetime import *

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

def cal(x, y):
    if(x == 1):
        return 1
    
    if(y == 1):
        return x
    
    #print(y, x-1)
    return (y)*(x-1)+1

def main():
    n = int(In())
    l = list(map(int, In().split()))
    
    ans = 0
    for i, x in enumerate(l, 1):
        ans = ans + cal(x, i)
        #print(ans)
        
    print(ans)
    
if __name__ == '__main__':
    main()
