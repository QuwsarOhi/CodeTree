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
    inputGrab()
    #print("DONE")
    
    t = nextInt()
    
    while t > 0:
        n = nextInt()
        
        a = n//2;
        if n%2 != 0:
            a += 1
             
        b = n;
        gcd = min(a, b);
        
        #print(a, b, gcd)
        
        print("1", end = "");
        for i in range(a-gcd):
            print("0", end = "");
        print(" 1", end = "");
        for i in range(b-gcd):
            print("0", end = "");
        print();
        t -= 1
    
    
if __name__ == '__main__':
    main()

