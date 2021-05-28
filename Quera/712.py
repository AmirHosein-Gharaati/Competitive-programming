def name(index):
    global rev
    for i in range(-1,-len(rev)-1,-1):
        if rev[i][0] <=index <= rev[i][1]:
            mid = (rev[i][0] + rev[i][1]) / 2
            
            if index - mid <= 0:
                index = index + 2*(abs(index-mid))
            else:
                index = index - (2*(abs(index-mid)))
    return int(index)



n = int(input())
rev = []
t = int(input())

for i in range(t):
    c = input().split()
    if c[0] == 'NAME':
        index = name(int(c[1]))
        print(index)
    else:
        rev.append([int(c[1]),int(c[2])])
        
        