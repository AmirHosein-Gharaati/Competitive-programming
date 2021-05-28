number = int(input())
temp1=''
temp2 =''

if len(str(number//100)) <= 1:
    temp1 = '0'
if len(str(number%100)) <= 1:
    temp2 = '0'

print('saal:' + temp1 + str(number//100))
print('maah:' + temp2 + str(number%100))