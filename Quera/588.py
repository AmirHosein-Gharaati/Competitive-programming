n=int(input())
x=input().split()
y=0
for i in range(n):
    if int(x[i])>y:
        y=int(x[i])
print(y)