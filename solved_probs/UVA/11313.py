# UVa
# 11313 - Gourmet Games

import sys

#sys.stdin = open('in', 'r')
#sys.stdout = open('out', 'w')

def Out(x):
	sys.stdout.write(str(x) + '\n')

def In():
	return sys.stdin.readline().strip()

def main():
	t = int(In())
	
	for Case in range(t):
		n, m = list(map(int, In().split()))
		# Explanation:
		# there is always m-1 contestant eliminated
		# and from all the candidates, only 1 candidate is selected at last
		# so, there remains n-1 candidates
		# if n-1 is divisable by m-1, then the show is possible
		if (n-1)%(m-1) == 0:
			print(int((n-1)/(m-1)))
		else:
			print('cannot do this')

if __name__ == '__main__':
	main()
