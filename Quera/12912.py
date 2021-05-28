def rec(list_base,starting_point):
    global n
    
    
    for i in range(starting_point,n+1):
        temp = list_base + [i]
        temp = list(map(str,temp))
        print('{'+', '.join(temp)+'}')
        rec(temp,i+1)
    

n = int(input())
a = []
print('{}')
rec(a,1)