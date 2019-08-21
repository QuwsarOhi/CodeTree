from math import *

def main():
	s = input()
	n = int(s, 2)

	k = 1
	ans = 0

	if n != 0:
		ans = 1

	while k*4 < n:
		k = k * 4
		ans += 1

	print(ans)


if __name__ == "__main__":
	main()
