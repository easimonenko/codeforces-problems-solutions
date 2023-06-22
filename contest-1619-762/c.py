t = int(input())

for _ in range(t):
    a, s = input().split()
    if len(a) > len(s):
        print("-1")
        break
    b = []
    ok = True
    rev_a = list(reversed(a))
    rev_s = list(reversed(s))
    for i in range(len(rev_s) - len(rev_a)):
        rev_a.append('0')
    s_idx = 0
    for i in range(len(s)):
        if s_idx >= len(s):
            if i < len(a):
                ok = False
            break
        dig_a = int(rev_a[i])
        dig_s = int(rev_s[s_idx])
        dig_b = dig_s - dig_a
        if dig_b >= 0:
            b.append(dig_b)
            s_idx = s_idx + 1
        elif s_idx + 1 < len(s):
            two_digs = dig_s + int(rev_s[s_idx + 1]) * 10
            dig_b = two_digs - dig_a
            if dig_b >= 0 and dig_b <= 9:
                b.append(dig_b)
                s_idx = s_idx + 2
            else:
                ok = False
                break
        else:
            ok = False
            break
    if ok:
        while b[-1] == 0:
            del b[-1]
        print(''.join(list(map(str, list(reversed(b))))))
    else:
        print("-1")
