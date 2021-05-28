def solver(new_p,n):
    global p
    pp = {}
    if n == 1:
        return new_p
    for i in new_p:
        for j in p:
            if i+j in pp:
                pp[i+j] += new_p[i] * p[j]
            else:
                pp[i+j] = new_p[i] * p[j]
    return solver(pp,n-1)
    



line = input().split()
m = int(line[0])
n = int(line[1])

p = {}
line = list(map(int,input().split()))
for i in range(m+1):
    p[i] = line[i]

res = solver(p,n)
for i in res:
    print(res[i],end= ' ')
    
