# UVa
# 550 - Multiplying by Rotation

import sys

#sys.stdin = open('in', 'r')
#sys.stdout = open('out', 'w')

def Out(x):
	sys.stdout.write(str(x) + '\n')

def In(x):
	return map(x, sys.stdin.readline().strip().split())

def main():
	for line in sys.stdin:
		base, factor, multiplier = map(int, line.strip().split())
		significant_product = factor * multiplier
		number = 1
		while(significant_product != factor):
			#print(significant_product)
			#print((significant_product%base)*multiplier, int(significant_product/base))
			significant_product = (significant_product%base)*multiplier + int(significant_product/base) 	# Significant_product + carry (if exists)
			number += 1
		Out(number)
if __name__ == '__main__':
	main()
