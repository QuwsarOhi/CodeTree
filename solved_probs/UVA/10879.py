# UVa
# 10879 - Code Refactoring


import sys
from math import sqrt

#sys.stdin = open('in', 'r')
#sys.stdout = open('out', 'w')

def Out(x):
	sys.stdout.write(str(x) + '\n')

def In():
	return sys.stdin.readline().strip()

def main():
	t = int(In())
	
	for Case in range(t):
		n = int(In())
		lim = int(sqrt(n))+1
		count = 0
		ans = []
		for i in range(2, lim):
			if count >= 2:
				break
			if n % i == 0:
				ans.append(i)
				ans.append(n/i)
				count += 1
		print('Case #%d: %d = %d * %d = %d * %d' %(Case+1, n, ans[0], ans[1], ans[2], ans[3]))



if __name__ == '__main__':
	main()
