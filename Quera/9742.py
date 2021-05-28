def Add(line):
    global data
    index = 0
    for i in range(len(data)):
        if line[3] < data[i][3]:
            break
        index += 1
    data.insert(index,line)
    print(f'User {line[3]} added successfully')
    
    
    
    
def search(name):
    global data
    datas = []
    name_len = len(name)
    for i in range(len(data)):
        data_name = data[i][3]
        if data_name[:name_len] == name:
            datas.append(data[i])
        elif name < data_name[:name_len]:
            break
    return datas

def Sort(sub_li): 
    sub_li.sort(key = lambda x: x[3]) 
    return sub_li
        

data = []
find_count = 0
while 1 :
    try:
        line = input().split()
        if line[0] == 'Add':
            Add(line[1:])
        else:
            find_count += 1
            datas = search(line[1])
            if datas == []:
                print(f'{find_count} No user found')
            else:
                count = 0
                Sort(datas)
                for i in datas:
                    if count == 10:
                        break
                    print('{} {}'.format(find_count,' '.join(i)))
                    count += 1
    except:
        break