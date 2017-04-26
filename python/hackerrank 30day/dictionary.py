#!usr/bin/env python3

n = int(input().strip())
Dic = dict()

for i in range(0, n):
    name, number = input().strip().split(' ')
    Dic[name] = number

for i in range(0, n):
    name = input().strip()
    if name in Dic:
        print(name + '=' + Dic[name])
    else:
        print('Not found')
