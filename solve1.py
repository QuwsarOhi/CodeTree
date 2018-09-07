from sys import *
#from bisect import *
#from collections import *
#from itertools import *
from fractions import *
#from datetime import *

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

inputIDX = 0
def hasNext():
    global inputIDX
    return (inputIDX < len(Input))

def nextInt():
    global inputIDX
    inputIDX += 1
    return int(Input[inputIDX-1])

def nextString():
    global inputIDX
    inputIDX += 1
    return Input[inputIDX-1]

'''--------------------------------------------------------------------------------'''


def main():
    inputGrab()     # Grabs input from inputstream, so that newline spaces doesn't causes runtime errors
    
    ## Main Code Goes Here
    
    #n = int(input())    # Taking inputs by default IOstream
    n = int(Input[0])    # Taking inputs by inputGrab()
    k = int(Input[1])
    
    lo = 0
    hi = 1000000000000000010
    ans = 1000000000000000010
    
    while lo <= hi:
        mid = (lo+hi)//2;
        area = mid*n;
        
        if area == k:
            ans = area
            break
        elif area > k:
            if mid < ans:
                ans = mid
            hi = mid-1
        else:
            lo = mid+1
    print(ans)
    
if __name__ == '__main__':
    main()
