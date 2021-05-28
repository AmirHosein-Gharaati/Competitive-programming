number=int(input())
x=number
reverse=0
while number>0:
    r=number%10
    reverse=reverse*10+r
    number=number//10
if reverse==x:
    print("YES")
else:
    print("NO")