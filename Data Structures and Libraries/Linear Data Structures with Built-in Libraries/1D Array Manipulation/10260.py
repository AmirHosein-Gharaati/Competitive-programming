lis = [
    ['B', 'F', 'P', 'V'],
    ['C', 'G', 'J', 'K', 'Q', 'S', 'X', 'Z'],
    ['D', 'T'],
    ['L'],
    ['M', 'N'],
    ['R'],
]

dic = {}

for i in range(len(lis)):
    for char in lis[i]:
        dic[char] = i+1
    
while True:
    try:
        string = input()
        last_digit = 0
        for char in string:
            if char in dic:
                if last_digit != dic[char]:
                    temp = dic[char]
                    print(temp, end='')
                    last_digit = temp
            else:
                last_digit = 0
        print()
    except:
        break