import sys

def energy_f(number):
    global energy
    energy += number
    if energy < 0:
        print(f'Frog died! Energy {energy}!')
        sys.exit(0)
    print(f'Energy {energy}!')

def jump(string):
    lis = string[2:len(string)-1].split(',')
    row = int(lis[0])
    column = int(lis[1])
    
    global x,y,game_x,game_y
    if 0 <= row < x and 0 <= column < y:
        print(f'Jump to ({row},{column})')
        game_x = row
        game_y = column
        checker()
        return True
    else:
        print('Impossible place!')
        return False

def location():
    global game_x,game_y
    print(f'Location ({game_x},{game_y})')
    
    
def crocodile():
    global energy
    print(f'Frog hunted by crocodile :-/! Energy {energy}!')
    sys.exit(0)
    
def change_place(command):
    global game_x,game_y,x,y
    if command == 'up':
        if 0<= game_x-1 < x:
            game_x -= 1
        else:
            print('Impossible place!')
            return False
    elif command == 'down':
        if 0<= game_x+1 < x:
            game_x += 1
        else:
            print('Impossible place!')
            return False
    elif command == 'right':
        if 0<= game_y+1 < y:
            game_y += 1
        else:
            print('Impossible place!')
            return False
    elif command == 'left':
        if 0<= game_y-1 < y:
            game_y -= 1
        else:
            print('Impossible place!')
            return False
    return True
            
def checker():
    global game_x,game_y,lis
    place = lis[game_x][game_y]
    if 'j' in place :
        jump(place)
    elif 'e' in place:
        energy_f(int(place[2:len(place)-1]))
    elif 'c' in place:
        crocodile()
    
def game():
    checker()
    while 1:
        command = input().lower().strip()
        if command == 'finish':
            energy_f(0)
            return
        elif command in ['up','down','right','left']:
            if change_place(command):
                checker()
        elif command == 'location':
            location()

energy = 0
game_x = 0
game_y = 0

x,y = input().split('*')
x = int(x.strip())
y = int(y.strip())
lis = [input().strip().lower().split() for i in range(x)]

game()
