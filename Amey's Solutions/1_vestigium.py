T = int(input())
for case in range(T):
    n = int(input())
    
    matrix = [list(map(int, input().split())) for _ in range(n)]
    matrix_t = [[row[index] for row in matrix] for index in range(n)]
    
    [k, r, c] = [0, 0, 0]
    for i in range(n):
        k += matrix[i][i]
        r += 1 if(len(set(matrix[i])) != n) else 0
        c += 1 if(len(set(matrix_t[i])) != n) else 0
    
    print("Case #{}: {} {} {}".format(case + 1, k, r, c))