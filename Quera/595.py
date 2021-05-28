n=int(input())
l1=[1,1]
l2=[1,1]
print(1)
for i in range(n-1):
    for k in range(len(l2)):
        print(l2[k], end=" ")
    l1=l2
    l2=[1,1]
    for j in range(len(l1)-1):
        l2.insert(j+1,l1[j]+l1[j+1])
    print("")