# UVa
# 11247 - Income Tax

import sys

#sys.stdin = open('in', 'r')
#sys.stdout = open('out', 'w')

def Out(x):
	sys.stdout.write(str(x) + '\n')

def In(x):
	return map(x, sys.stdin.readline().strip().split())

# This function calculates the exact number after which the money(after giving tax) is >= money-1
def ml(money, percent):
	return ((money-1)*100)/(100-percent)

def main():
	eps = 1**-9
	while True:
		money, percent = In(int)
		if money == percent == 0:
			break
		elif money == 0 or percent == 0 or percent == 100:
			Out('Not found')
		else:
			x = ml(money, percent)
			if x - int(x) != 0:		# If the number is float, then take the floor value
				x = int(x)
			else:
				x = int(x) - 1		#If the number is int value, then take the previous value, which is actually less than money

			if x >= money:			# if the money that we calculated is >= the money limit
				Out(x)
			else:
				Out('Not found')
		
if __name__ == '__main__':
	main()
