def change_base(number,base):
    global lis
    res =''
    while number > 0:
        res = lis[number%base] + res
        number = number // base
    return res






lis = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9','A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J']
n = int(input())
for i in range(1,301,1):
    res = change_base(i**2,n)
    if res == res[::-1]:
        print(change_base(i,n),res)
    