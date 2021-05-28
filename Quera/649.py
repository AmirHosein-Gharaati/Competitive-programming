a=int(input())
b=int(input())
d=""
for i in range(a+1, b):
    c=1
    for j in range(2, i):
        if i%j==0:
            c=0
            break
    
    if c==1:
        if d == "":
            d = d + str(i)
        else:
            d= d +"," + str(i)
print(d)
