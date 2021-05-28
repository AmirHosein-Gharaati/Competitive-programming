n=int(input())
b=0
m=n
d=0
while n>0:
    b=n%10+b
    n=n//10
while d<b:
    m+=1
    c=1
    for i in range(2,m):
        if m%i==0:
            c=0
            break
    if c==1:
        d+=1
print(m)
    