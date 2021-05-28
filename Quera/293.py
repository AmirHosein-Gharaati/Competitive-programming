a=int(input())
b=int(input())
for i in range(a,b+1):
    c=1
    for j in range(2, i):
        if i%j==0:
            c=0
            break
    if c==1 and i!=1:
        print(i)
            