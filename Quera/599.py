from math import sqrt
def solve(b,c):
    global vx
    a = -5
    temp = b**2 - 4*a*c
    if temp < 0:
        print('impossible')
        return
    elif temp == 0:
        t = -b/(2*a)
        print('{:.2f}'.format(vx*t))
        return

    else:
        s1 = (-b + sqrt(b**2 - 4*a*c))/(2*a)
        s2 = (-b - sqrt(b**2 - 4*a*c))/(2*a)
        if s1 >= 0 :
            t = s1
            temp = vx*t
            print('{:.2f}'.format(temp))
        if s2 >= 0:
            t = s2
            temp = vx*t
            print('{:.2f}'.format(temp))
        if s1 <0 and s2 < 0:
            print('impossible')
            return

vx, vy , y0, h = input().split()
vx = float(vx)
vy = float(vy)
y0 = float(y0)
h = float(h)
solve(vy,y0-h)