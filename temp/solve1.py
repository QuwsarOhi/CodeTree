import sys

#sys.stdin = open('in', 'r')
#sys.stdout = open('out', 'w')


def Out(x):
    sys.stdout.write(str(x) + '\n')

def In():
    return sys.stdin.readline().strip()

Input = []              # This list contains inputs index by index
def inputGrab():
    for line in sys.stdin:
        inputArr.extend(map(str, line.strip().split()))

def main():
    #inputGrab()     # Grabs input from inputstream, so that newline spaces doesn't causes runtime errors
    
    ## Main Code Goes Here
    
    n = int(input())    # Taking inputs..
    m = int(input())    # Taking inputs..
    
    
if __name__ == '__main__':
    main()
