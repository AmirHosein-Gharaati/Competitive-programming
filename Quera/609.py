from math import sqrt

n = int(input())
lis =[]
for i in range(n):
    lis+= [(list(map(int,input().split())))]

row = 0
column = 0
maxi = n-1
mini = 0
result = 0
count = 0
while(row!=int(n/2) or column!=int(n/2)):
    while(column<= maxi):
        result += lis[row][column]
        if sqrt(result) == int(sqrt(result)):
            count += 1
        column += 1
    column -= 1
    row += 1

    while(row<= maxi):
        result += lis[row][column]
        if sqrt(result) == int(sqrt(result)):
            count += 1
        row += 1
    row -= 1
    column -= 1
    
    maxi -= 1
    
    while(column>= mini):
        result += lis[row][column]
        if sqrt(result) == int(sqrt(result)):
            count += 1
        column -= 1
    column += 1
    row -= 1
    mini += 1

    while(row>= mini):
        result += lis[row][column]
        if sqrt(result) == int(sqrt(result)):
            count += 1
        row -= 1
    row += 1
    column += 1
if n%2 == 1:
    result += lis[row][column]
    if sqrt(result) == int(sqrt(result)):
        count += 1
print(count)
        
        