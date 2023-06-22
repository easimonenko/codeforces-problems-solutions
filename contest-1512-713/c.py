# TODO: incomplete solution.

t = int(input())

for k in range(t):
    a, b = list(map(int, input().split()))
    n = a + b
    p = input()
    res = True
    ans = []

    for i in range(n):
        ans.append('*')

    for i in range(n):
        if p[i] == '0':
            a = a - 1
            ans[i] = '0'
        elif p[i] == '1':
            b = b - 1
            ans[i] = '1'

    m = n // 2
    if n % 2 == 1:
        m = m + 1
    for i in range(m):
        if p[i] != p[n - 1 - i]:
            if p[i] != '?' and p[n - 1 - i] != '?':
                res = False
                break
            elif p[i] == '?':
                ans[i] = p[n - 1 - i]
                ans[n - 1 - i] = p[n - 1 - i]
                if p[n - 1 - i] == '0':
                    a = a - 1
                else:
                    b = b - 1
            elif p[n - 1 - i] == '?':
                ans[i] = p[i]
                ans[n - 1 - i] = p[i]
                if p[i] == '0':
                    a = a - 1
                else:
                    b = b - 1
        elif p[i] == '?' and p[n - 1 - i] == '?':
            if i == n - 1 - i:
                d = 1
            else:
                d = 2
            if a - d >= 0:
                ans[i] = '0'
                ans[n - 1 - i] = '0'
                a = a - d
            elif b - d >= 0:
                ans[i] = '1'
                ans[n - 1 - i] = '1'
                b = b - d
            else:
                res = False
                break

    if a != 0 or b != 0:
        res = False

    if res:
        print(''.join(ans))
    else:
        print(-1)

    #print(a, b)
    #print(''.join(ans))
