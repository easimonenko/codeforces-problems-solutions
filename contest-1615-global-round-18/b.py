# TODO: incomplete solution.

t = int(input())

zs = []
zs[0][0] = [1]
for x in range(1, 200000 + 1):
    y = x
    zs.append(list())
    while y > 0:
        y, r = divmod(y, 2)
        if r == 0:
            zs[x].append(zs[x - 1] + 1)

for k in range(t):
    l, r = list(map(int, input().split()))
