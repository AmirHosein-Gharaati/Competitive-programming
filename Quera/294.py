from math import sqrt

def checker(a,b,c):
    if a == 0 and b == 0 and c != 0:
        print('IMPOSSIBLE')
        return
    
    if a == 0 and b!=0:
        res = (-c/b)
        if res == 0:
            res = abs(res)
        print('{:.3f}'.format(res))
        return

    temp = (b**2 - 4*a*c)
    if temp < 0 :
        print('IMPOSSIBLE')
        return
    elif temp == 0:
        res = (-b) / 2*a
        if res == 0:
            res = abs(res)
        print('{:.3f}'.format(res))
        return
    else:
        rishe1 = ((-b) + sqrt(b**2 - 4*a*c)) / (2*a)
        riseh2 = ((-b) - sqrt(b**2 - 4*a*c)) / (2*a)
        lis = [rishe1,riseh2]
        lis.sort()
        print('{:.3f}'.format(lis[0]))
        print('{:.3f}'.format(lis[1]))


a = float(input())
b = float(input())
c = float(input())

checker(a,b,c)
