# TODO: incomplete solution.

t = int(input())
for k in range(t):
    n, m = list(map(int, input().split()))
    if n == 2 and m == 2:
        print("BW")
        print("BB")
        continue
    board = [['W' for j in range(m)] for i in range(n)]
    for i in range(1, n+1):
        for j in range(1, m+1):
            if i == n and j == m and (n % 2 == 0 or m % 2 == 0):
                board[i-1][j-1] = 'B'
            elif i % 2 != 0 and j % 2 != 0:
                board[i-1][j-1] = 'B'
            elif i % 2 != 0 and j % 2 == 0:
                board[i-1][j-1] = 'W'
            elif i % 2 == 0 and j % 2 != 0:
                board[i-1][j-1] = 'W'
            elif i % 2 == 0 and j % 2 == 0:
                board[i-1][j-1] = 'B'
    for i in range(n):
        print(''.join(board[i]))
