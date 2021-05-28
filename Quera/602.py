from math import floor

moadele1 = lambda x : x - floor(x)
moadele2 = lambda x : x**2 + x
moadele3 = lambda x : abs(-(x**3)+1) + (x**3)

def checker(n):
    results = []
    lis = []
    for i in range(n):
        lis = []
        temp = input().split()
        x = float(temp[0])
        y = float(temp[1])

        if abs(moadele1(x) - y) <= 0.2:
            lis.append(1)
        if abs(moadele2(x) - y) <= 0.2:
            lis.append(2)
        if abs(moadele3(x) - y) <= 0.2:
            lis.append(3)
        
        results.append(lis)
    return results

n = int(input())
res = checker(n)

lis = [True]*3

for i in res:
    if 1 not in i:
        lis[0] = False
    if 2 not in i:
        lis[1] = False
    if 3 not in i:
        lis[2] = False

if True not in lis:
    print('No ones')
else:
    for i in range(len(lis)):
        if lis[i] == True:
            print(i+1)