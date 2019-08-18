
def main():
	s = input()
	t = input()

	tcnt = dict()
	scnt = dict()

	for c in t:
		if c not in tcnt:
			tcnt[c] = 1
		else:
			tcnt[c] += 1

	for c in s:
		if c not in scnt:
			scnt[c] = 1
		else:
			scnt[c] += 1

	for x, y in t.items():
		if x not in scnt:
			print("-1")
			return
		else:
			




if __name__ == "__main__":
	main()
