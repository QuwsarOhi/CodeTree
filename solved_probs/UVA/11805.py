# UVa
# 11805 - Bafana Bafana

import sys

#sys.stdin = open('in', 'r')
#sys.stdout = open('out', 'w')

def Out(x):
	sys.stdout.write(str(x) + '\n')

def In():
	return sys.stdin.readline().strip()

def main():
	t = int(In())
	Case = 1
	for _ in range(t):
		N, K, P = map(int, In().split())
		ans = (K+P) % N
		if ans == 0:
			ans = N
		print('Case %d: %d' %(Case, ans))
		Case+=1
	
if __name__ == '__main__':
	main()
