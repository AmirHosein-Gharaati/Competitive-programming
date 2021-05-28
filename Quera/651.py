a=int(input())
b=int(input())
c=int(input())

i=0
adad=0
num = ''

while a>0:
    adad=adad+((b**i)*(a%10))
    a=a//10
    i+=1
    
while adad>0:
    num = str(adad%c) + num
    adad=adad//c
    
test_palindrome=int(num)
test1 = test_palindrome
reverse = 0
while test_palindrome > 0:
    reverse=(reverse*10)+(test_palindrome%10)
    test_palindrome=test_palindrome//10
if test1==reverse:
    print("YES")
else:
    print("NO")