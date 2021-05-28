def checker(substring):
    global strings
    for i in strings:
        if substring in i or substring[::-1] in i:
            pass
        else:
            return False
    return True


n = int(input())

strings = [input() for i in range(n)]

longest_sub = ''
index = 0
starting_point = 0

while index != len(strings[0]):
    index += 1
    substring = strings[0][starting_point:index]
    res = checker(substring)
    if res:
        if len(substring) > len(longest_sub):
            longest_sub = substring
    else:
        starting_point += 1
        index = starting_point
    
print(longest_sub)
