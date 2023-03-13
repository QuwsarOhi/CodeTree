from sys import stdin, stdout

# Update recursion limit
#from sys import setrecursionlimit, getrecursionlimit
#setrecursionlimit(1000000)
#print(getrecursionlimit())


def input(): 
    return stdin.readline()

# use f-string
def print(inp, end='\n'):
    stdout.write(inp+end)

print(f"This is a {12}")