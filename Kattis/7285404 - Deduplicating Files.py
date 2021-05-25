def hash_val(string):
    res = ord(string[0])
    
    for i in range(1, len(string)):
        res = res ^ ord(string[i])

    return res





while True:
    n = int(input())
    if n == 0:
        break

    lis = []
    
    for _ in range(n):
        line = input()
        lis.append([line, hash_val(line)])

    no_unique = 0
    hash_col = 0

    for i in range(n):
        string1, hash1 = lis[i]
        flag_for_unique = True
        for j in range(i+1, n, 1):
            string2, hash2 = lis[j]

            if hash1 == hash2:
                if string1 == string2:
                    flag_for_unique = False
                else:
                    hash_col += 1

        if flag_for_unique == True:
            no_unique += 1
    
    print(no_unique, hash_col)