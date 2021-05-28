def fact(n):
    if n== 0:
        return 1
    Sum = 1
    i = 1
    while i <= n:
        Sum *= i
        i += 1
    return Sum

def comb(i,j):
    return fact(i)//(fact(i-j)*fact(j))

def calc(n):
    summ = 0
    for i in range(1,n+1,1):
        s = 1
        for j in range(1,i,1):
            s *= comb(i,j)
        summ += s
        
    return summ


n = int(input())
print(calc(n))