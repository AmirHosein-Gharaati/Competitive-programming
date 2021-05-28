a=int(input())
b=2
c= a-2
d=c
while b>0:
    print(a*"*")
    while d>0:
        print("*" + c * " " + "*")
        d-=1
    b-=1
    