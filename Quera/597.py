n = int(input())
count = 2
lis = [1,0]
if n == 1:
    print('0 0')
elif n == 2:
    print('1 0')
else:
    while True:
        lis[1] = (-lis[1])+1
        count += 1
        if count == n:
            print(lis[0],lis[1])
            break
        lis[0] = -lis[0]
        count += 1
        if count == n:
            print(lis[0],lis[1])
            break
        lis[1] = -lis[1]
        count += 1
        if count == n:
            print(lis[0],lis[1])
            break
        lis[0] = (-lis[0]) + 1
        count += 1
        if count == n:
            print(lis[0],lis[1])
            break
        