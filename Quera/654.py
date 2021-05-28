from math import sqrt

def cal(n):
    for num1 in range(1,n):
        num2 = (n**2 - 2*n*num1) // (2*(n-num1))
        if num1 + num2 + sqrt(num1**2 + num2**2) == n:
            num3 = n - (num1 + num2)
            lis = [num1,num2,num3]
            lis.sort()
            if 0 in lis:
                return 'Impossible'
            else:
                lis = list(map(str,lis))
                return ' '.join(lis)
    return 'Impossible'

n = int(input())
print(cal(n))