t = int(input())

for _ in range(t):
    l1, l2, l3 = list(map(int, input().split()))
    p, r = divmod(l1 + l2 + l3, 2)
    if r != 0:
        print("NO")
    else:
        if (l1 == l2 and (l3 % 2 == 0)) or (l1 == l3 and (l2 % 2 == 0)) or (l2 == l3 and (l1 % 2 == 0)):
            print("YES")
        elif (l1 + l2 == l3) or (l1 + l3 == l2) or (l2 + l3 == l1):
            print("YES")
        else:
            print("NO")
