# UVa
# 10624 - Super Number

import sys
#sys.stdin = open('in', 'r')
#sys.stdout = open('out', 'w')

def backtrack(num, n, m):
	if n > m:
		return num

	num *= 10
	if num % n != 0:
		diff = n - (num % n)
		if diff >= 10:
			return -1
		else:
			last_digit = diff
	else:
		last_digit = 0
	

	for i in range(last_digit, 10, n):
		tmp = num + i
		if tmp == 0:
			continue
		if tmp % n == 0:
			ans = backtrack(tmp, n+1, m)
			if ans != -1:
				return ans

	
	return -1
	

def main():
	t, = In(int)


	for _ in range(t):
		n, m  = In(int)
		print('Case %d: ' %(_+1), end='')
		
		if n == 1:
			print(backtrack(0, 1, m))
		
		else:	
			start = 10 ** (n-1)
			lim = start * 10
			found = False
			
			if start % n != 0:
				start = start + (n - (start % n))
			
			for x in range(start, lim, n):
				ans = backtrack(x, n+1, m)
				if ans != -1:
					found = True
					print(ans)
					break
			
			if not found:
				print('-1')
		

def Out(x):
	sys.stdout.write(str(x) + '\n')

def In(x):
	return map(x, sys.stdin.readline().strip().split())

if __name__ == '__main__':
	main()
