n=int(input())
for i in range(1,2*n+2,2):
    print(int((2*n+2-i)/2) * " " + i*"*")
for j in range(2*n-1,0,-2):
    print(int((2*n+2-j)/2) * " " + j*"*")