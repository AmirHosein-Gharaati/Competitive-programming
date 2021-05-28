from math import sqrt

def find_next_prime(number):
    number += 1
    while True:
        flag = 0
        for i in range(2,int(sqrt(number))+1,1):
            if number % i == 0:
                flag = 1
                number += 1
                break
        
        if flag == 0:
            return number

dicc = {}


n = int(input())
prime = 1

while n != 1:
    prime = find_next_prime(prime)
    while n % prime == 0:
        if prime in dicc:
            dicc[prime] += 1
        else:
            dicc[prime] =1
        n = n // prime

lis = []
for i in dicc:
    if dicc[i] == 1:
        lis.append(str(i))
    else:
        lis.append(str(i)+'^'+str(dicc[i]))
print('*'.join(lis))
    
