import math

def cal(n) :
    count = 0
    i = 1
    while i <= math.sqrt(n):
        if (n % i == 0) : 
            if (n / i == i) : 
                count += 1
            else : 
                count += 2
        i = i + 1
    return count

n = 1
k = int(input())
while True:
     number = int((1 + n) * n / 2)
     if cal(number) >= k:
         print(number)
         break
     n += 1