<<<<<<< HEAD
def DistinctList(arr): 
    l = len(arr)
    arr = sorted(arr)
    past = arr[0]
    ans = 0

    for i in range(1, l):
        if arr[i] == past:
            ans += 1
        past = arr[i]


    return ans
    # code goes here 
    #return arr
    
# keep this function call here  
print DistinctList(raw_input())  


  
=======
from math import *

def test(lim):
    ans = inf

    for mask in range(lim):
        l = []
        for i in range(lim):
            if mask & (1 << i):
                
>>>>>>> 70a5491588d00ec98f196356c1f76d863f3bdd71
