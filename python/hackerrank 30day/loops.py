#!/bin/python3

n = int(input().strip())

# table of input number
for x in range(1, 11):
    print("%d x %d = %d" %(n, x, x*n))
