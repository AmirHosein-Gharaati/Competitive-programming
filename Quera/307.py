def SHIFT_R(N):
    global string
    if len(string) != 0:
        temp = (-N)%len(string)
        string = string[temp:] + string[:temp]

def SHIFT_L(N):
    global string
    if len(string) != 0:
        temp = N % len(string)
        string = string[temp:] + string[:temp]

def EXTEND(N):
    global string
    string = string + N*'*'

def SHRINK(N):
    global string
    if len(string) - N <= 0:
        string = ''
    else:
        string = string[:-N]

def REVERSE():
    global string
    string = string[::-1]

def PUT(i,c):
    global string
    string = string[:i-1] + c + string[i:]

string = input()


while 1:
    command = input().split()
    if command[0] == 'EXIT':
        break
    elif command[0] == 'PRINT':
        print(string)
        
    elif command[0] == 'SHIFT-R':
        SHIFT_R(int(command[1]))
        
    elif command[0] == 'SHIFT-L':
        SHIFT_L(int(command[1]))
    elif command[0] == 'EXTEND':
        EXTEND(int(command[1]))
        
    elif command[0] == 'SHRINK':
        SHRINK(int(command[1]))
        
    elif command[0] == 'REVERSE':
        REVERSE()
    elif command[0] == 'PUT':
        PUT(int(command[1]),command[2])