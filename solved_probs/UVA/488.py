# UVa
# 488 - Triangle Wave
# Fast IO and Output formatting

import sys

#sys.stdin = open('in', 'r')
#ys.stdout = open('out', 'w')

def wave(a):
	for i in range(1, a+1):
		for j in range(i):
			Out(i)#print(i, end="")
		Out("\n")
	for i in range(a-1, 0, -1):
		for j in range(i):
			Out(i)#print(i, end="")
		Out("\n")

def main():
	t, = In(int)
	for _ in range(t):
		In(str)
		a, = In(int)
		f, = In(int)
		for i in range(f):
			wave(a)
			if i != f-1:
				Out("\n")
		if _ != t-1:
			Out("\n")
	
def Out(x):
	sys.stdout.write(str(x))

def In(x):
	return map(x, sys.stdin.readline().strip().split())

if __name__ == '__main__':
	main()
