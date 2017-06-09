import sys

x, y = map(int, sys.stdin.readline().split())

x = str(x-y)

if x[0] != '1':
	print('1' + x[1:])
elif x[0] != '2':
	print('2' + x[1:])
elif x[0] != '3':
	print('3' + x[1:])
elif x[0] != '4':
	print('4' + x[1:])
elif x[0] != '5':
	print('5' + x[1:])
elif x[0] != '6':
	print('6' + x[1:])
elif x[0] != '7':
	print('7' + x[1:])
elif x[0] != '8':
	print('8' + x[1:])
elif x[0] != '9':
	print('9' + x[1:])
