import math

t = int(input())

for i in range(t):
    n = int(input())
    res = set()
    for x in range(1, math.floor(math.sqrt(n)) + 1):
        d = x * x
        res.add(d)
        q = d * x
        if q <= n:
            res.add(q)
    print(len(res))