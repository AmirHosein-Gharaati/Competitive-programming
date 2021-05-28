def create(string,index):
    las_appendeds = []
    new_str = ''
    while string[index] != '}':
        if string[index] == ',':
            try:
                las_appendeds.append(int(new_str))
                new_str = ''
            except:
                pass
        elif string[index] == '{':
            result = create(string,index+1)
            index = result[0]
            las_appendeds.append(result[1])
        elif string[index] == ' ':
            index += 1
            continue
        else:
            new_str += string[index]
            
        index += 1
        
    try:
        las_appendeds.append(int(new_str))
        new_str = ''
    except:
        pass
    
        
    print(sum(las_appendeds))
    
    return [index,sum(las_appendeds)]
    

my_list = []

string = input()

create(string,1)