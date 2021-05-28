def check_ord(word):
    global bi_seda
    start = 0
    end = 5
    while end <= len(word):
        flag = 0
        for letter in range(start,end,1):
            if word[letter] < 'A' or word[letter] > 'z' or word[letter] in bi_seda:
                start = letter + 1
                end = start + 5
                flag = 1
                break
        if flag == 0:
            return False
        
    return True

bi_seda = ['a','A','i','I','o','O','u','U','e','E','y','Y']

line = input()
puncs = ["!", ".", "?", ",", ":", ";", "(", ")", "'", "\"", " "]
for punc in puncs:
    line = line.replace(punc, " ")
line = line.split()
for word in line:
    if len(word) >= 5:
        if word.upper() == word or check_ord(word):
            continue
        else:
            print(word, end = ' ')
