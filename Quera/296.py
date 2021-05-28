def drawer(n):
    temp = n * ['#']
    temp2 = n * [' ']
    temp2[0] = '#'
    temp2[-1] = '#'
    lis = []
    lis.append(temp.copy())
    for i in range(n-2):
        lis.append(temp2.copy())
    lis.append(temp.copy())

    for i in range(n):
        lis[i][i] = '#'
    j = n-1
    for i in range(n):
        lis[i][j] = '#'
        j -= 1
        
    for line in lis:
        j = n-2
        while line[j] != '#':
            line[j] = '#'
            j -= 1
    
    for i in lis:
        print(''.join(i))




n = int(input())

if n == 1:
    print('#')
else:
    drawer(n)