num = int(input())

x1 = 0
x2 = 1
fib = 1
lis = []
while(fib <= num):
    lis.append(fib)
    x1 = x2
    x2 = fib
    fib = x1 + x2
i = len(lis)-1
while (num > 0):
    if lis[i] <= num:
        print(i+1,end=' ')
        num -= lis[i]
    i -= 1