number = input()
length = len(str(number)) - 1

number = int(number)

while length >= 0:
    digit = (number // (10**length)) % 10
    print(str(digit) + ': ' + digit*str(digit))
    length -= 1