n = int(input())

Sum = 0

for i in range(n):
    
    num = input()
    
    Sum += int(num[:-1]) ** int(num[-1])
    
print(Sum)