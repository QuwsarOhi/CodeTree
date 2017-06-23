# UVa
# 105 - the skyline problem
# Height map

import sys

#sys.stdin = open('in', 'r')
#sys.stdout = open('out', 'w')

def main():
	h = [0]*10005
	
	for line in sys.stdin:
		L, H, R = map(int, line.strip().split())
		for i in range(L, R):
			if H > h[i]:
				h[i] = H
	
	pastHeight = 0
	firstOutput = True
	for i in range(10000):
		if pastHeight != h[i]:
			if firstOutput == False:
				Out(' ')
			firstOutput = False
			print('%d %d' %(i, h[i]), end='')
			pastHeight = h[i]
	print()




def Out(x):
	sys.stdout.write(str(x))

def In(x):
	return map(x, sys.stdin.readline().strip().split())

if __name__ == '__main__':
	main()
