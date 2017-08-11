# UVa
# 11934 - Magic Formula

import sys

#sys.stdin = open('in', 'r')
#sys.stdout = open('out', 'w')

def Out(x):
	sys.stdout.write(str(x) + '\n')

def In(x):
	return map(x, sys.stdin.readline().strip().split())

def f(a, b, c, x):
	return a*x*x + b*x + c

def main():
	while True:
		a, b, c, d, L = In(int)
		cnt = 0
		if a == b == c == d == L == 0:
			break
		if d == 0:
			print('0')
			continue
		for x in range(L+1):
			k = f(a, b, c, x)
			if k % d == 0:
				cnt += 1
		print(cnt)
	
	
if __name__ == '__main__':
	main()
