# brent returns a divisor not guaranteed to be prime, returns n if n prime (PYTHON)
from fractions import gcd
from random import randint
from sys import stdin

def brent(N):
    if N%2==0: 
        return 2
    
    y,c,m = randint(1, N-1),randint(1, N-1),randint(1, N-1)
    g,r,q = 1,1,1
   
    while g == 1:             
        x = y
        for i in range(r):
            y = ((y*y)%N+c)%N
        k = 0
        while (k<r and g==1):
            ys = y
            for i in range(min(m,r-k)):
                y = ((y*y)%N+c)%N
                q = q*(abs(x-y))%N
            g = gcd(q,N)
            k = k + m
        r = r*2
    if g==N:
        while True:
            ys = ((ys*ys)%N+c)%N
            g = gcd(abs(x-ys),N)
            if g > 1:
                break
    return g


def power(x, y, p): 
    res = 1;  
    x = x % p;  
    while (y > 0): 
        if (y & 1): 
            res = (res * x) % p;  
        y = y>>1; # y = y/2 
        x = (x * x) % p; 
      
    return res; 
  
def miillerTest(d, n): 
    a = 2 + randint(1, n - 4); 
  
    # Compute a^d % n 
    x = power(a, d, n); 
  
    if (x == 1 or x == n - 1): 
        return True; 

    while (d != n - 1): 
        x = (x * x) % n; 
        d *= 2; 
  
        if (x == 1): 
            return False; 
        if (x == n - 1): 
            return True; 
  
    # Return composite 
    return False; 
  
def isPrime( n, k): 
    # Corner cases 
    if (n <= 1 or n == 4): 
        return False; 
    if (n <= 3): 
        return True; 
    d = n - 1; 
    while (d % 2 == 0): 
        d //= 2; 
  
    # Iterate given nber of 'k' times 
    for i in range(k): 
        if (miillerTest(d, n) == False): 
            return False; 
  
    return True; 

def getDiv(x):
    while True:
        ret = brent(x)
        #print("GOT", x, "=", ret)
        if ret != x and ret > 1 and isPrime(ret, 10):
            return ret

Input = []

def inputGrab():
    for line in stdin:
        Input.extend(map(str, line.strip().split()))

inputIDX = 0
def hasNext():
    global inputIDX
    return (inputIDX < len(Input))

def nextInt():
    global inputIDX
    inputIDX += 1
    return int(Input[inputIDX-1])

def nextString():
    global inputIDX
    inputIDX += 1
    return Input[inputIDX-1]

def main():
    inputGrab()
    t = nextInt()

    for Case in range(1, t+1):
        n = nextInt()
        l = nextInt()

        primeMul = []
        for i in range(l):
            primeMul.append(nextInt())

        SET = set()
        mulVals = []
        vals = []

        for i in range(len(primeMul)):
            x = getDiv(primeMul[i])
            y = primeMul[i]//x

            #print(primeMul[i], " = ", x, " * ", y)
            mulVals.append({x, y})
            SET.add(x)
            SET.add(y)

        for x in SET:
            vals.append(x)

        vals.sort()

        #for x in vals:
        #    print(x)
        #print("TOTLEN", len(vals))

        getChar = dict()

        for i in range(len(vals)):
            getChar[vals[i]] = chr(i+65)

        ans = []
        lim = len(mulVals)-1
        for i in range(lim):
            x1, y1 = mulVals[i]
            x2, y2 = mulVals[i+1]

            if x1 == x2:
                if i == 0:
                    ans.append(getChar[y1])
                ans.append(getChar[x2])
                if i == lim-1:
                    ans.append(getChar[y2])
            elif x1 == y2:
                if i == 0:
                    ans.append(getChar[y1])
                ans.append(getChar[y2])
                if i == lim-1:
                    ans.append(getChar[x2])
            elif y1 == x2:
                if i == 0:
                    ans.append(getChar[x1])
                ans.append(getChar[x2])
                if i == lim-1:
                    ans.append(getChar[y2])
            else:
                if i == 0:
                    ans.append(getChar[x1])
                ans.append(getChar[y2])
                if i == lim-1:
                    ans.append(getChar[x2])

        print("Case #" + str(Case) + ": ", end="")
        for x in ans:
            print(x, end="")
        print()
        #print("TOTLEN :", len(ans))

main()