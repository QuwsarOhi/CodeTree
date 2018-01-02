import sys
from bisect import *

INF = 1e9
Input = []
MOD = 1000000007

#sys.stdin = open('in', 'r')
#sys.stdout = open('out', 'w')

def Out(x):
    sys.stdout.write(str(x) + '\n')

def In():
    return sys.stdin.readline().strip()

def inputGrab():
    for line in sys.stdin:
        Input.extend(map(str, line.strip().split()))

############################################################

isPrime = [True for i in range(5100)]
primes = []
divCount = {}

def sieve(lim = 5100):
    global isPrime
    global primes
    
    isPrime[0] = isPrime[1] = 0
    for i in range(2, lim):
        if isPrime[i]:
            primes.append(i)
            for j in range(i+i, lim, i):
                isPrime[j] = 0


def factorize(val):
    global primes
    global divCount
    
    for prime in primes:
        if val < prime:
            break
        if val % prime == 0:
            divCount[prime] += 1
        while val >= prime and val % prime == 0:
            val /= prime
    if val != 1:
        primes.append(val)
        if val not in divCount:
            divCount[val] = 1
        else:
            divCount[val] += 1



def main():
    n = int(In())
    v = map(int, In().split())
    global divCount
    global primes
    
    sieve(50)

    # Key value mapping
    for prime in primes:
        divCount[prime] = 0

    # factorize
    for elem in v:
        factorize(elem)

    
    past = 0
    print("before cSum")
    for key, value in divCount.items():
        print(key, value)

    # Cumulative frequency
    past = 0
    for key, value in divCount.items():
        past += value
        divCount[key] = past

    print("After cSum")
    for key, value in divCount.items():
        print(key, value)

    # Prime Number print
    for elem in primes:
        print(elem, end = ' ')
    print()

    q = int(In())
    for i in range(q):
        l, r = map(int, In().split())
        lftPoint = bisect_left(primes, l)
        rhtPoint = bisect_right(primes, r)

        if rhtPoint != 0:
            rhtPoint -= 1

        print(lftPoint, rhtPoint)
        print(primes[lftPoint], primes[rhtPoint])
        ans = divCount[primes[rhtPoint]]
        print("Sum at right point", rhtPoint, primes[rhtPoint], ans)
        if lftPoint != 0:
            lftPoint -= 1
            print("Sum at left point", lftPoint, primes[lftPoint])
            ans -= divCount[primes[rhtPoint]]
        print(ans)
    
if __name__ == '__main__':
    main()
