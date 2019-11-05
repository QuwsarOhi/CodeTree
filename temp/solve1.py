
def compress(x):
    ret = []
    for i in range(100):
        c = x.count(i)
        if c%2 > 0:
            ret.append(i)
    return ret

def f(x):
    ret = []
    for i in range(1, len(x)):
        ret.append(compress(x[i-1]+x[i]))
    return ret

def brute(x):
    y = []
    for xx in x:
        y.append([xx])
    while len(y) > 1:
        print(y)
        y = f(y)
    print(y)
    return y


def test():
    for i in range(1, 36):
        print('For I =', i)
        brute([j for j in range(1, i+1)])
        print()

if __name__ == '__main__':
    test()