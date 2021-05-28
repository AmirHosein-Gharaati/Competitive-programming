def cal(lis,start):
    if len(lis) == 1:
        return lis[0]
    del lis[start]
    start = (start+1) % len(lis)
    return cal(lis,start)

n = int(input())
List = list(range(1,n+1))
print(cal(List,1))