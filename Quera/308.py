def IsPalindrome(string):
    signs = ['.','?','!',' ']
    string = [i.lower() for i in string if i not in signs]
    reverse = string[::-1]
    if reverse == string:
        return 'YES'
    else:
        return 'NO'


string = input()

print(IsPalindrome(string))

    