# UVa
# 12290 - Counting Game
# Note: No outpt is -1, there is solution for every input

import sys

#sys.stdin = open('in', 'r')
#sys.stdout = open('out', 'w')

def Out(x):
	sys.stdout.write(str(x) + '\n')

def In():
	return sys.stdin.readline().strip()

def bruteforce(n, m, k):
	s = n*2-2
	count = 0
	for i in range(1, sys.maxsize):
		if i%7 == 0 or str(i).find('7') != -1:
			x = i - int(i/s)*s
			if x == 0:
				x = 2
			if x <=n:
				if x == m:
					count+=1
			else:
				x = n - (x-n)
				if x == m:
					count+=1
			if count == k:
				return i

def main():
	while True:
		n, m, k = list(map(int, In().split()))
		if n == m == k == 0:
			break
		print(bruteforce(n, m, k))

if __name__ == '__main__':
	main()
