
line = input().lower()
line = ' ' + line + ' '
word = input().lower()
rev_word = word[::-1]

word_len = len(word)
count = 0

for i in range(len(line)):
    if line[i] == word[0] or line[i] == rev_word[0]:
        try:
            if line[i:i+word_len] == word and (line[i-1] < 'a' or line[i-1] > 'z') and (line[i+word_len]< 'a' or line[i+word_len] > 'z'):
                count += 1
            if line[i:i+word_len] == rev_word and (line[i-1] < 'a' or line[i-1] > 'z') and (line[i+word_len]< 'a' or line[i+word_len] > 'z'):
                count += 1
        except:
            pass


print(count)
