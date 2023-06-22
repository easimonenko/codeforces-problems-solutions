t = int(input())

for _ in range(t):
    n = int(input())
    p = list(map(int, input().split()))
    s = input()
    tr = list()
    res = [0 for i in range(n)]
    for i in range(n):
        tr.append([s[i], p[i], i + 1])
    tr_s = list(sorted(tr))
    for i in range(n):
        res[tr_s[i][2] - 1] = i + 1
    print(' '.join(map(str, res)))
