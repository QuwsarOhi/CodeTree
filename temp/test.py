import sys
import math
sys.stdin = open('in', 'r')
#sys.stdout = open('out', 'w')

dp = []
val = []


def Knapsack():
	
'''
def Knapsack(totalWeight, collectedWeight, coinNo, totalCoin):
	global dp
	print('collectedWeight, coinNo', collectedWeight, coinNo)
	
	if coinNo == totalCoin or totalWeight == collectedWeight:
		print('returning', collectedWeight, coinNo,collectedWeight)
		return collectedWeight
	
	#print('coin no', coinNo)	
	if dp[collectedWeight][coinNo] != -1:
		print('returning dp[%d][%d] : %d' %(collectedWeight, coinNo, dp[collectedWeight][coinNo]))
		return dp[collectedWeight][coinNo]
	
	if collectedWeight + val[coinNo] > totalWeight:
		return Knapsack(totalWeight, collectedWeight, coinNo+1, totalCoin)
	
	dp[collectedWeight][coinNo] = max(Knapsack(totalWeight, collectedWeight+val[coinNo], coinNo+1, totalCoin), Knapsack(totalWeight, collectedWeight, coinNo+1, totalCoin))
	print('got collectedWeight %d, coinNo %d : %d' %(collectedWeight, coinNo, dp[collectedWeight][coinNo]))
	
	return dp[collectedWeight][coinNo]
'''
def main():
	t, = In(int)
	for _ in range(t):
		n, = In(int)
		global val, dp
		val.clear()
		dp.clear()
		val = list(In(int))
		dp = [[-1]*102]*27000
		total = sum(val)
		half_c = math.ceil(total/2)
		half_f = int(total/2)
		print(total, half_f, len(val))
		knap = Knapsack(half_f, len(val)-1)
		taken = half_f - knap
		print(total, knap, taken)
		print(abs((total - taken) - taken))
		#Knap = Knapsack(half_f, 0, 0, len(val))
		#print(half_f, Knap)
		#print(int(2* (total/2 - Knap)))
		for i in range(len(val)):
			for j in range(27):
				print('%d %d : %d' %(j, i, dp[j][i]))
	
def Out(x):
	sys.stdout.write(str(x))

def newLine(x):
	sys.stdout.write(str(x)+'\n')

def In(x):
	return map(x, sys.stdin.readline().strip().split())

if __name__ == '__main__':
	main()
