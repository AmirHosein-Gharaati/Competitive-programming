n1=int(input())
n2=int(input())
c=0
while c>=0:
    print(n1)
    c=n2-n1
    n2=n1
    n1=c
    if n1==0:
        break