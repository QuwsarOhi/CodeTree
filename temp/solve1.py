import sys
from bisect import *

#sys.stdin = open('in', 'r')
#sys.stdout = open('out', 'w')


def Out(x):
    sys.stdout.write(str(x) + '\n')

def In():
    return sys.stdin.readline().strip()

Input = []
def inputGrab():
    for line in sys.stdin:
        Input.extend(map(int, line.strip().split()))

def main():
    inputGrab()
    
    
    
    
if __name__ == '__main__':
    main()
