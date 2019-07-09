from sys import stdin, stdout
#from fractions import *
#from bisect import *
#from collections import deque

class scanner:
    inputIDX = 0
    Input = []
    
    # File Read/Write
    stdin = stdin
    #stdin = open('in', 'r')
    #stdout = open('out', 'w')
    
    def __init__(self):
        self.inputGrab()

    def Out(self, x, end="\n"):
        stdout.write(str(x) + end)

    def In(self):
        return stdin.readline().strip()

    def inputGrab(self):
        for line in self.stdin:
            self.Input.extend(map(str, line.strip().split()))

    def hasNext(self):
        return True if self.inputIDX < len(self.Input) else False

    def nextInt(self):
        self.inputIDX += 1
        return int(self.Input[self.inputIDX-1])

    def nextString(self):
        self.inputIDX += 1
        return self.Input[self.inputIDX-1]

'''--------------------------------------------------------------------------------'''

v = [-1 for i in range(100)]    # Initializing array of size 100 by -1

# bisect_left(array, val, lo, hi)
# bisect_right(array, val, lo, hi)

def main():
    # Main Function


=======
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
    #inputGrab()     # Grabs input from inputstream, so that newline spaces doesn't causes runtime errors
    
    ## Main Code Goes Here
    
    n = int(input())    # Taking inputs by default IOstream
    m = int(Input[0])    # Taking inputs by inputGrab()
    
    test = [-1 for i in range(10)]      # Memset -1 of size 10 [0, 9]
    
    for i in range(10):
        print(test[i], end = '')
    
if __name__ == '__main__':
    main()
