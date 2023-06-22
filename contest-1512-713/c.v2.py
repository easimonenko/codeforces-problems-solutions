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

    if n % 2 == 1 and p[n // 2] == '?':
        if a % 2 == 1:
            ans[n // 2] = '0'
            a = a - 1
        elif b % 2 == 1:
            ans[n // 2] = '1'
            b = b - 1
        else:
            res = False

    for i in range(n // 2):
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
            if a - 2 >= 0:
                ans[i] = '0'
                ans[n - 1 - i] = '0'
                a = a - 2
            elif b - 2 >= 0:
                ans[i] = '1'
                ans[n - 1 - i] = '1'
                b = b - 2
            else:
                res = False
                break

    if a != 0 or b != 0:
        res = False

    if res:
        print(''.join(ans))
    else:
        print(-1)

    print(a, b)
    print(''.join(ans))
