# UVa
# 10070 - Leap Year or Not Leap Year and ...
# Biginteger Required!

import sys
import math
#sys.stdin = open('in', 'r')
#sys.stdout = open('out', 'w')

def isLeapYear(y):
	if y%4 == 0 and y%100 != 0:
		return True
	elif y % 400 == 0:
		return True
	return False

def main():
	first = True
	for line in sys.stdin:
		y = int(line.strip())
		if first == False:
			print('')
		first = False
		found = False
		if isLeapYear(y):
			print("This is leap year.")
			found = True
		if y % 15 == 0:
			print("This is huluculu festival year.")
			found = True
		if y % 55 == 0 and isLeapYear(y):
			print("This is bulukulu festival year.")
			found = True
		if found == False:
			print("This is an ordinary year.")
		
	
def Out(x):
	sys.stdout.write(str(x))

def In(x):
	return map(x, sys.stdin.readline().strip().split())

if __name__ == '__main__':
	main()
