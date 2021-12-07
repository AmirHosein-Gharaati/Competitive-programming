


while True:
    line = input()
    if line ==  "0000 0000 0000 0000":
        break

    line = ''.join(line.split(" "))
    line = [int(chr) for chr in line]

    sum1 = []
    sum2 = []

    for i in range(0, len(line), 2):
        digit = line[i]
        temp = digit*2 if digit*2 < 10 else (digit*2)-9
        sum1.append(temp)

    for i in range(1, len(line), 2):
        digit = line[i]
        sum2.append(digit)
    
    res = sum(sum1) + sum(sum2)
    if res % 10 == 0:
        print('Yes')
    else:
        print('No')
