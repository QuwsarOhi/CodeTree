#!usr/bin/env python3

n = int(input().strip())
max_cnt = cnt = 0

for i in range(0, 31):
	if n & (1 << i):
		cnt += 1
	else:
		max_cnt = max(cnt, max_cnt)
		cnt = 0
print(max_cnt)
