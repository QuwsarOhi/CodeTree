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
'''
..-..-..
..-..-..
..-..-..
..-..-..
..-..-..
..-..-..
'''

def main():
    s = [[], [], [], [], [], []]
    con = [ [3, 3, 4, 4, 3, 3],
            [3, 3, 4, 4, 3, 3],
            [2, 2, 3, 3, 2, 2],
            [2, 2, 3, 3, 2, 2],
            [1, 1, 2, 2, 1, 1],
            [1, 1, 2, 2, 1, 1]]
            
    maxX = -1
    maxY = -1
    maxPoint = -1
    
    for i in range(6):
        Tmp = input()
        j = 0
        for chars in Tmp:                
            s[i].append(chars)
            
            if chars == '-':
                continue
            
            if chars == '.' and con[i][j] > maxPoint:
                maxX = i
                maxY = j
                maxPoint = con[i][j]
                #print("At", i, j, "Char is", chars)
            j += 1

    #print(maxX, maxY)
    Printed = False
    
    for i in range(6):
        j = 0
        for chars in s[i]:
            if i == maxX and j == maxY and not Printed and chars != '-':
                print("P", end='')
                Printed = True
            else:
                print(chars, end='')
            if chars != '-':
                j += 1
        print()
    
    
if __name__ == '__main__':
    main()
