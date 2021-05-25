

while True:

    try:
        keys = list(map(int, input().split()[1:]))
        phrase = input()
        keys_len = len(keys)
        if len(phrase)%len(keys) != 0:
            phrase += (keys_len-(len(phrase)%len(keys)))* ' '
        new_string = ''
        for i in range(0, len(phrase), keys_len):
            sub_str = phrase[i:i+keys_len]
            temp = ''

            for j in keys:
                temp += sub_str[j-1]
            new_string += temp

        print(f'\'{new_string}\'')

    except EOFError:
        break