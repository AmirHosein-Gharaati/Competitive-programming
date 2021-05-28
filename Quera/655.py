def corrector(x):
    lis=[]
    y=""
    x=x.lower()
    for j in range(len(x)-1,-1,-1):
        if x[j-1]==" ":
            y=(x[j].upper())+y
        if j==0:
            y=(x[j].upper())+y
            break
        if x[j-1]!=" ":
            y=x[j]+y
    return y
lis1=[]
n=int(input())
for i in range(n):
    x=input()
    lis1.append(corrector(x))
for k in range(len(lis1)):
    print(lis1[k])