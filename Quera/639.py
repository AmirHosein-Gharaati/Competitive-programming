def checker(substring,strings):
    for string in strings:
        if not(substring in string or substring[::-1] in string):
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

    if checker(substring,strings):
        
        if len(substring) > len(longest_sub):
            longest_sub = substring
    else:
        starting_point += 1
        index = starting_point
    
print(longest_sub)
