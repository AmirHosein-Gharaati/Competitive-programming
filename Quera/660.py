dicc = {}

n = int(input())

for i in range(n):
    name = input()
    dicc[name] = 0

for i in range(n):
    name = input()
    line = input().split(' ')
    main_money = int(line[0])
    counts = int(line[1])

    if counts == 0:
        dicc[name] += main_money
        continue
    
    dicc[name] += (main_money % counts) - main_money

    for j in range(counts):
        friend_name = input()
        dicc[friend_name] += main_money // counts
    
for name in dicc:
    print(name,dicc[name])