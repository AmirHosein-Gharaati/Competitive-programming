string = input()

saved_char = string[0]
counter = 1
maxx = 1
for i in range(1, len(string)):

    if string[i] == saved_char:
        counter += 1
    else:
        saved_char = string[i]
        counter = 1
    maxx = max(counter, maxx)
print(maxx)