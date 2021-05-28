def solver(t):
    for i in range(len(t)-2,-1,-1):
        for j in range(len(t[i])):
            t[i][j] = max(t[i+1][j]+t[i][j],t[i+1][j+1]+t[i][j])
            
    print(t[0][0])
    



tt = int(input())

for i in range(tt):
    length = int(input())
    triangle = []
    for j in range(length):
        triangle.append(list(map(int,input().split())))
    solver(triangle)
    



