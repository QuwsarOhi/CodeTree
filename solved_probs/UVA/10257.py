# UVa
# 10257 - Dick and Jane

''' The main concept of the problem is find three ages (spot, puff and yertle) where

i) spot > puff > yertel
ii) spot + puff + yerte = 12 + j

if these two are satisfied, any solution is accepted
'''

import sys

#sys.stdin = open('in', 'r')
#sys.stdout = open('out', 'w')

def Out(x):
	sys.stdout.write(str(x) + '\n')

def In(x):
	return map(x, sys.stdin.readline().strip().split())

def main():
	for line in sys.stdin:
		s, p, y, j = map(int, line.strip().split())
		# Total age = Dicks age + Janes age
		# x + x+y + x+p = j + 12
		# Yertle, Spot, Puff = Dick + Jane
		total = j + 12
		yertle = int((total - p - y)/3)
		puff = int((total - yertle - s)/2)
		spot = total - puff - yertle
		print(spot, puff, yertle)

if __name__ == '__main__':
	main()
