#!usr/bin/env python3

r = [0, 0, 0, 1, 2, 2, 2]
c = [0, 1, 2, 1, 0, 1, 2]

mat = []
max_total = -10000000

for i in range(6):
	arr = [int(num) for num in input().strip().split(' ')]
	mat.append(arr)		# adding array in array [creates 2d matrix]
	    
for i in range(6):
	for j in range(6):
		total = 0
		ok = True
		for pos in range(7):
			x = i + r[pos]
			y = j + c[pos]
			
			if x >= 6 or y >= 6 or x < 0 or y < 0:
				ok = False
				continue
			if mat[x][y] != 0:
				total += mat[x][y]
		if ok:
			max_total = max(max_total, total)

for i in range(6):
	for j in range(6):
		total = 0
		ok = True
		for pos in range(7):
			x = i - r[pos]
			y = j - c[pos]
			
			if x >= 6 or y >= 6 or x < 0 or y < 0:
				ok = False
				continue
			if mat[x][y] != 0:
				total += mat[x][y]
		if ok:
			max_total = max(total, max_total)

print(max_total)
