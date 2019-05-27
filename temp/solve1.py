from math import *

def test(lim):
    ans = inf

    for mask in range(lim):
        l = []
        for i in range(lim):
            if mask & (1 << i):
                