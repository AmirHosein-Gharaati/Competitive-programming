adad1 , adad2 = map(int,input().split())
maxx = max(adad1,adad2)
for i in range(2,maxx):
    if adad1%i == adad2%i:
        print(i,end=' ')
