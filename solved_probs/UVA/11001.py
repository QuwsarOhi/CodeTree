# UVa
# 11001 - Necklace

import sys
import math
#sys.stdin = open('in', 'r')
#sys.stdout = open('out', 'w')

def cal(v_total, v):
	if v >= v_total:
		return 0
	return 0.3 * math.sqrt(v_total - v)


def main():
	eps = 10 ** -7
	while True:
		v_total, v = In(int)
		if v_total == v == 0:
			break
		max_val = 0.0
		n = 0
		for i in range(1, v_total-v):
			val = i*cal(v_total/i, v)
			#print(val, i)
			if abs(val - max_val) <= eps:
				max_val = n = 0
				#print('ok')
				break
			elif val > max_val:
				max_val = val
				n = i
			#else:
			#	break
		
		print(n)

def Out(x):
	sys.stdout.write(str(x))

def newLine(x):
	sys.stdout.write(str(x)+'\n')

def In(x):
	return map(x, sys.stdin.readline().strip().split())

if __name__ == '__main__':
	main()
