
def find_first_square(num):
    while int(num**(0.5)) != num**(0.5):
        num += 1
    
    return num

n = int(input())
for _ in range(n):
    string = input()
    num = find_first_square(len(string))
    # print(num)
    string += (num-len(string)) * '*'
    length = len(string)
    root = int(num**(0.5))
    square = [[char for char in string[i:i+root]] for i in range(0, length, root)]
    length = len(square)

    for column in range(length):
        for row in range(length-1, -1, -1):
            if square[row][column] != '*':
                print(square[row][column], end='')
    print()