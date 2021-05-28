def copy(key,count):
    global final_string
    
    string = key* int(count)
    
    final_string = string + final_string[len(string):]
    

def compare(key) -> int:
    global final_string
    
    if key == final_string:
        return 1
    else:
        return 0
    
def substr(key,count) -> int:
    global final_string
    length = len(key)
    c = 0
    
    for i in range(len(final_string)):
        if final_string[i:i+length] == key:
            c += 1
    if c == int(count):
        return 1
    else:
        return 0
    
def attach(key,count,string) -> int:
    global final_string
    key += string
    length = len(key)
    
    c=0
    
    for i in range(len(final_string)):
        if final_string[i:i+length] == key:
            c += 1
    if c == int(count):
        return 1
    else:
        return 0

    
def length(count) -> int:
    
    global final_string
    
    if len(final_string) == int(count):
        return 1
    else:
        return 0

final_string = input()
value = 0
counter = 0

while True:
    line = input().split()
    counter += 1
    cm = line[0]
    if cm == 'copy':
        copy(line[1],line[2])
        
    elif cm == 'compare':
        value += compare(line[1])
        
    elif cm == 'substr':
        value += substr(line[1],line[2])
        
    elif cm == 'attach':
        value += attach(line[1],line[2],line[3])
        
    elif cm == 'length':
        value += length(line[1])
        
    elif cm == 'Is':
        counter -= 1
        if (counter / 2) <= value:
            print('Eyval')
        else:
            print('HeifShod')
        break
        
        