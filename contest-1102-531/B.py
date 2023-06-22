n, k = list(map(int, input().split()))
a = list(map(int, input().split()))

c = {}

result = True

for x in a:
    counter = c.get(x)
    if counter:
        c[x] = counter + 1
    else:
        c[x] = 1
    if c[x] > k:
        result = False
        break

if result:
    print("YES")
    coloring = []
    next_color = {}
    for x in a:
        nc = next_color.get(x)
        if nc:
            coloring.append(nc)
            next_color[x] = nc + 1
        else:
            coloring.append(1)
            next_color[x] = 2
    print(" ".join(map(str, coloring)))
else:
    print("NO")
