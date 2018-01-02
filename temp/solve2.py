from sys import *
from bisect import *
from collections import *

INF = 1e9
Input = []
MOD = 1000000007

stdin = open('in', 'r')
#stdout = open('out', 'w')

def Out(x):
    stdout.write(str(x) + '\n')

def In():
    return stdin.readline().strip()

def inputGrab():
    for line in stdin:
        Input.extend(map(str, line.strip().split()))

############################################################

isPrime = [True for i in range(7100)]
primes = []
divCount = {}

def sieve(lim = 7000):
    global isPrime
    global primes
    
    isPrime[0] = isPrime[1] = 0
    for i in range(2, lim):
        if isPrime[i]:
            primes.append(i)
            for j in range(i*i, lim, i):
                isPrime[j] = 0


def factorize(val, Cnt):
    global primes
    global divCount
    
    for prime in primes:
        if val < prime:
            break
        if val % prime == 0:
            divCount[prime] += Cnt
        while val >= prime and val % prime == 0:
            val /= prime
    if val != 1:
        if val not in divCount:
            divCount[val] = Cnt
            primes.append(val)
        else:
            divCount[val] += Cnt



def main():
    n = int(In())
    v = map(int, In().split())
    global divCount
    global primes
    

        
    
if __name__ == '__main__':
    main()

