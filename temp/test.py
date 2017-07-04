import sys

#sys.stdin = open('in', 'r')
#sys.stdout = open('out', 'w')

def lcs(s1, s2):
    m, n = len(s1), len(s2)
    C = [[0]*(n+5)]*(m+5)
    for i in range(1, m + 1):
        for j in range(1, n + 1):
            if s1[i - 1] == s2[j - 1]:
                C[i][j] = C[i - 1][j - 1] + 1
            else:
                C[i][j] = max(C[i][j - 1], C[i - 1][j])
    return C[m][n]

def main():
    t, = In(int)
    t += 1
    for i in range(1, t):
        In(str)
        prince = list(In(int))
        princess = list(In(int))
        res = lcs(prince, princess)
        print("Case %d: %d" % (i, res))


def Out(x):
	sys.stdout.write(str(x))

def In(x):
	return map(x, sys.stdin.readline().strip().split())

if __name__ == '__main__':
	main()
