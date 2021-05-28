adad1,adad2,adad3 = map(int,input().split())
matris1 = []
matris2 = []
for i in range(adad1):
    matris1.append(list(map(int,input().split())))
for i in range(adad2):
    matris2.append(list(map(int,input().split())))
new_lis = []
for i in range(adad1):
    result = []
    for j in range(adad3):
        summ = 0
        for k in range(adad2):
            summ += matris1[i][k] * matris2[k][j]
        result.append(summ)
    new_lis.append(result)
for i in range(len(new_lis)):
    print(' '.join(list(map(str,new_lis[i]))))