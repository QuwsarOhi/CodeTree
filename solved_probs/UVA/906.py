# UVa
# 906 - Rational Neighbor

import sys

#sys.stdin = open('in', 'r')
#sys.stdout = open('out', 'w')

def Out(x):
	sys.stdout.write(str(x) + '\n')

def In(x):
	return map(x, sys.stdin.readline().strip().split())

def main():
	for line in sys.stdin:
		a, b = map(float, line.strip().split())
		n, = In(float)
		eps = 10**-14
		r1 = float(a)/b
		d = 1
		while True:
			c = int(r1*d)
			while a*d >= c*b:
				c+=1
			if (float(c)/d - r1) - n <= eps:
				Out(str(c) + ' ' + str(d))
				break
			d+=1

if __name__ == '__main__':
	main()
