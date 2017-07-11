import sys

#sys.stdin = open('in', 'r')
#sys.stdout = open('out', 'w')


def main():
    #s, = In(str)


def Out(x):
	sys.stdout.write(str(x))

def In(x):
	return map(x, sys.stdin.readline().strip().split())

def ReadLine():
	return sys.stdin.readline().strip()

if __name__ == '__main__':
	main()
