from sys import *
#from bisect import *
#from collections import *
#from itertools import *
#from fractions import *
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
    
    tc = nextInt()

    for i in range(tc):
        a = nextInt()
        b = nextInt()
        c = nextInt()
        n = nextInt()

        if b-a == c-b:
            print('Case %d: %d'%(i+1, a+(n-1)*(b-a)))
        else:
            print('Case %d: Error'%(i+1))

if __name__ == '__main__':
    main()

