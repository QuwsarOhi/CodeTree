# UVa
# 11614 - Etruscan Warriors Never Play Chess
import sys
from math import sqrt, floor

#sys.stdin = open('in', 'r')
#sys.stdout = open('out', 'w')

def Out(x):
	sys.stdout.write(str(x) + '\n')

def In():
	return sys.stdin.readline().strip()

def main():
	t = int(In())
	for _ in range(t):
		n = int(In())
		ans = (sqrt(1 + (8 * n)) - 1) / 2
		#print(ans)
		ans = floor(ans)
		Out(ans)
		
if __name__ == '__main__':
	main()
