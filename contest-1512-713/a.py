t = int(input())

for k in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    for i in range(n - 2):
        if a[i] != a[i + 1] and a[i] == a[i + 2]:
            print(i + 1 + 1)
            break
        elif a[i] != a[i + 1] and a[i] != a[i + 2]:
            print(i + 1)
            break
        elif a[i] != a[i + 2] and a[i + 1] != a[i + 2]:
            print(i + 2 + 1)
            break
        else:
            continue
