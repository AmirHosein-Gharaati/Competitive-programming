def getsub(lis,n):
    
    current = 0 if len(lis) == 0 else lis[-1]
    if current-1 == n:
        print(lis)
        return
    for i in range(current+1,n+1):
        z = lis + [i]
        getsub(z,n)
    print('{ ' + ' '.join(list(map(str,lis))) + ' }')

n = int(input())
getsub([],n)
