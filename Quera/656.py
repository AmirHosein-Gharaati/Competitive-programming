def determinant(matrix):
    deter=0
    if len(matrix)!=2:
        for k in range(len(matrix)):
            adad=matrix[0][k]
            if k%2==1:
                adad=-adad
            deter+=adad*determinant([[matrix[l][m] for m in range(len(matrix)) if m!=k]for l in range(len(matrix)) if l!=0])
    else:
        return (matrix[0][0]*matrix[1][1]-matrix[0][1]*matrix[1][0])
    return deter

n = int(input())

matrix1 = [input().split() for i in range(n)]
matrix1 = [[int(j) for j in i]for i in matrix1]

matrix2 = [input().split() for i in range(n)]
matrix2 = [[int(j) for j in i]for i in matrix2]

res = [[0 for x in range(n)] for y in range(n)]

for i in range(len(matrix1)): 
    for j in range(len(matrix2[0])): 
        for k in range(len(matrix2)):
            res[i][j] += matrix1[i][k] * matrix2[k][j]

res = determinant(res)


if res % 2  == 0:
    print('Farzad')
else:
    print('Danial')

