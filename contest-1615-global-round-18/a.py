t = int(input())

for k in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    s = sum(a)
    d, r = divmod(s, n)
    if r != 0:
        print(1)
    else:
        print(0)
