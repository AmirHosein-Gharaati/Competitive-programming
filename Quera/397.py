def changeChar(char):
    if char == '(':
        return ')'
    return '('

paran = input()

problems = 0
waiting_for_close = 0
index = 0

while index < len(paran):
    if paran[index] == '(':
        waiting_for_close += 1

    elif paran[index] == ')':
        waiting_for_close -= 1

    if waiting_for_close < 0:
        paran = paran[:index] + changeChar(paran[index]) + paran[index+1:]
        waiting_for_close += 1
        problems += 1
        continue
    index += 1

print(problems + int((waiting_for_close/2)))