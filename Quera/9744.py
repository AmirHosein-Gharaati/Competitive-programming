def solver(summ,row,listt,n,ac):
    global Max,matrix,lis
    if row == n:
        if summ < Max:
            Max = summ
            lis = listt[::]
        return
    if summ > Max:
        return

    for column in ac:
        temp = ac[::]
        temp.remove(column)
        solver(summ + matrix[row][column],row+1,listt+(column,),n,temp)

n = int(input())
lis = ()
matrix = [list(map(int,input().split())) for i in range(n)]
Max = 2147483647
solver(0,0,(),n,list(range(n)))

for i in lis:
    print(i)
