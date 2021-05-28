digits = '0123456789ABCDEF'

number, base = input().split()
number = int(number)
base = int(base)
final = ''

while number >0:
    final = digits[number%base] + final
    number = number // base
print(final)
    