import sys

n = int(input())

if n == 1:
    print(1)
    sys.exit(0)

if n in [2, 3]:
    print('NO SOLUTION')
    sys.exit(0)


if n == 4 :
    print('2 4 1 3')
    sys.exit(0)



lis1 = []
lis2 = []

for i in range(1, n+1):
    if i%2 == 0:
        lis2.append(i)
    else:
        lis1.append(i)

lis = lis1+lis2

lis = list(map(str, lis))

print(' '.join(lis))