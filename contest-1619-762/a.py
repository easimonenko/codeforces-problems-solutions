import math

t = int(input())

for i in range(t):
    s = input()
    m, r = divmod(len(s), 2)
    if r != 0:
        print("NO")
    else:
        res = True
        for i in range(0, m):
            if s[i] != s[m + i]:
                res = False
                break
        if res:
            print("YES")
        else:
            print("NO")
