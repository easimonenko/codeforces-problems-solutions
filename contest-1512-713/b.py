t = int(input())

for k in range(t):
    n = int(input())
    field = []
    ang1_x = 0
    ang1_y = 0
    ang1_found = False
    ang2_x = 0
    ang2_y = 0
    ang2_found = False
    for i in range(n):
        field.append(list(input()))
        for j in range(n):
            if field[i][j] == '*':
                if ang1_found:
                    ang2_x = i
                    ang2_y = j
                    ang2_found = True
                elif ang2_found:
                    break
                else:
                    ang1_x = i
                    ang1_y = j
                    ang1_found = True
    if ang1_x == ang2_x:
        if ang1_x == 0:
            field[n - 1][ang1_y] = '*'
            field[n - 1][ang2_y] = '*'
        else:
            field[0][ang1_y] = '*'
            field[0][ang2_y] = '*'
    elif ang1_y == ang2_y:
        if ang1_y == 0:
            field[ang1_x][n - 1] = '*'
            field[ang2_x][n - 1] = '*'
        else:
            field[ang1_x][0] = '*'
            field[ang2_x][0] = '*'
    else:
        field[ang1_x][ang2_y] = '*'
        field[ang2_x][ang1_y] = '*'

    for i in range(n):
        print(''.join(field[i]))
