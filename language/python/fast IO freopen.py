import sys
# sys.stdin = open('in', 'r')
# sys.stdout = open('out', 'w')

n, k = map(int, sys.stdin.readline().split())

cnt = 0
numbers = sys.stdin.readlines()

for num in numbers:
	if int(num) % k == 0:
		cnt += 1

# use stdin.write(string) to fast output

print(cnt)
