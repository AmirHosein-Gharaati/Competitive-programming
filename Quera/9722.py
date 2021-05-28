from math import sqrt

def isPrime(number):
    if number % 2 == 0 or number == 1:
        return False
    for i in range(3,int(sqrt(number))+1,2):
        if number % i == 0:
            return False
    return True

def cal(n):
    prime_numbers = ['2','3','5','7']
    if n == 1:
        return '\n'.join(prime_numbers)
    lis = ['2','3','5','7']
    new_list = []
    for i in range(1,n):
        for j in range(len(lis)):
            for k in range(1,10,2):
                new_number = lis[j] + str(k)
                if isPrime(int(new_number)):
                    new_list.append(new_number)
        lis = new_list.copy()
        new_list.clear()
    return '\n'.join(lis)

n = int(input())

print(cal(n))