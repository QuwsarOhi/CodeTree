'''
CodeChef
Bytelandian gold coins 
Problem Code: COINS
https://www.codechef.com/problems/COINS
'''

import sys

C = list(map(int, sys.stdin.readlines()))

mp = {}

def backtrack(money):
	money = int(money)
	#print(money)
	if(money == 0):
		return 0
	if str(money) in mp:
		return mp[str(money)]
	else:
		# print(int(money/2), int(money/3), int(money/4))
		maxVal = max(money, backtrack(money/2)+backtrack(money/3)+backtrack(money/4))
		mp[str(money)] = maxVal
		return maxVal

for c in C:
	mp.clear()
	if c == 0:
		print('0')
	else:
		print(backtrack(c))
