def f(m,s):
    lis = [-1,-1]
    if m == 1 and s == 0:
        return [0,0]
    if not 1<=s<=m*9:
        return lis
    mini = [0]*m
    maxi = [0]*m
    s1 = s
    i1 = m-1
    s2 = s
    i2 = 0 
    while(s1!=0):
        if mini[i1] == 9:
            i1 -=1
        if s1 == 1:
            if mini[0] == 0:
                mini[0] += 1
                break
            else:
                mini[i1] += 1
                break
        mini[i1] += 1
        s1 -= 1
    while(s2!=0):
        if maxi[i2] == 9:
            i2 +=1
        maxi[i2] +=1
        s2 -=1
    mini = list(map(str,mini))
    maxi = list(map(str,maxi))
    return [int(''.join(mini)),int(''.join(maxi))]

                
m , s= input().split()
m = int(m)
s = int(s)
result =f(m,s)
print(result[0],result[1])
