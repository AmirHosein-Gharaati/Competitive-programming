import numpy as np

matrix=[]
n=int(input())
for i in range(n):
    x=input().split()
    matrix.append(x)
matrix=[[float(matrix[i][j]) for j in range(n)] for i in range(n)]



print('{:.2f}'.format(np.linalg.det(matrix)))
