# UVa
# 10469 - To Carry or not to Carry
# Bitwise

from sys import stdin, stdout

def printf(x):
	stdout.write(str(x) + '\n')
	
def bit(x):	
	for i in range(31, -1, -1):
		if x & 1<<i:
			print(1, end="")
		else:
			print(0, end="")
	print()

def main():
	X = stdin.readlines()
	#print(X)
	for x in X:
		a, b = map(int, x.strip().split())
		num = []
		for i in range(31, -1, -1):
			#print(num)
			if ((a & 1<<i) | (b & 1<<i)) and ((a & 1<<i) & (b & 1<<i)) == False:
				num.append('1')
				#print('1 for', i)
				#print('num : ', num)
			else:
				num.append('0')
				#print('0 for', i)
		#print(num)
		printf(int(''.join(num), 2))

if __name__ == '__main__':
	main()
