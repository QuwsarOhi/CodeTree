#!/bin/python3

n = int(input().strip())

# strip = cuts last and first spaces AKA trims
# split = splits strings according to given token

arr = [int(arr_temp) for arr_temp in input().strip().split(' ')]	

for x in range(len(arr)-1, 0, -1):
    print(str(arr[x]) + ' ', end='')		# end='' is avoiding the new line
print(arr[0])
