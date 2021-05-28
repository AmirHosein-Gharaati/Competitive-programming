x=int(input())
y=int(input())
c=1
if x<0:
    x=x*(-1)
if y<0:
    y=y*(-1)
if x>y:
    for i in range(y,0,-1):
        if y%i==0 and x%i==0:
            print(i)
            c=0
            break
else:
    for i in range(x,0,-1):
        if y%i==0 and x%i==0:
            print(i)
            c=0
            break
if c==1:
    print(max(x,y))