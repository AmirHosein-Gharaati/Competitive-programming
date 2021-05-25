def get_key(val):
    global dic
    for key, value in dic.items():
         if val == value:
             return key

def cal(command):
    global dic
    string = ''

    for element in command:
        if element in ['+', '-']:
            string += element
        else:
            if element in dic:
                string += str(dic[element])
            else:
                return 'unknown'
    
    return eval(string)

dic = {}

while True:
    try:
        command = input().split()
        if command[0] == 'def':
            dic[command[1]] = int(command[2])
        elif command[0] == 'calc':
            res = cal(command[1:-1])
            if res in dic.values():
                print(' '.join(command[1:]) + ' ' + str(get_key(res)))
            else:
                print(' '.join(command[1:]) + ' ' + 'unknown')
        elif command[0] == 'clear':
            dic.clear()
    except EOFError:
        break