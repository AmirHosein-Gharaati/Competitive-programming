

while True:
    try:
        numbers = list(map(int , input().split()))[:-1]        
        maxV = -999999
        for j in range(len(numbers)):
            s =1
            for k in range(j, -1, -1):
                s = s * numbers[k]
                if(s > maxV):
                    maxV = s

        print(maxV)
    except:
        break