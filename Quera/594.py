a ,b = map(int,input().split())
i = 0
lis = []
while a>0:
    lis.insert(0,str(a%b))
    a //= b

sum1 = 0
sum2= 0
for i in range(0,len(lis),2):
    sum1 += int(lis[i])
for i in range(1,len(lis),2):
    sum2 += int(lis[i])
if sum1 == sum2 :
    print('Yes')
else:
    print('No')

