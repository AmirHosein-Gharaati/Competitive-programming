def minusBin(string,index):
    if string[index] == '0':
        string = string[:index] + '1' +string[index+1:]
        return minusBin(string,index-1)
    else:
        return string[:index] + '0' +string[index+1:]


n = input()

count = 0

for i in range(len(n)):
    count += 2**i

binn = bin(2**(len(n)))[2:]
binn = minusBin(binn,len(binn)-1)[1:]


while binn > n:
    count -= 1
    binn = minusBin(binn,len(binn)-1)

print(count)
    