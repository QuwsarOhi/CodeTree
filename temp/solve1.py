from sys import *
from bisect import *
from collections import *

INF = 1e9
Input = []
MOD = 1000000007

#stdin = open('in', 'r')
#stdout = open('out', 'w')

def Out(x):
    stdout.write(str(x) + '\n')

def In():
    return stdin.readline().strip()

def inputGrab():
    for line in stdin:
        Input.extend(map(str, line.strip().split()))

############################################################

def main():
    n, k = map(int, In().split())
    v = map(int, In().split())
    
    
    
if __name__ == '__main__':
    main()
