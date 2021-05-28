def cal(x,n):
    fac = 1
    SUM = 0
    if n == 0:
        return 0
    elif n == 1 or (x == 0 and n!= 1):
        return 1
    for i in range(n):
        if i!=0:
            fac *= i
        SUM += x**i / fac
    return SUM


x = int(input())
n = int(input())

print('{:.3f}'.format(cal(x,n)))
