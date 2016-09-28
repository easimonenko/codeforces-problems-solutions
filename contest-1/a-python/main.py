n, m, a = map(int, input().split())

print((n // a + (1 if n % a != 0 else 0)) * (m // a + (1 if m % a != 0 else 0)))
