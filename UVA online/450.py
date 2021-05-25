last_names = []
dep = ''

dic = {}

n = int(input())
while True:
    
    try:
        string= input()
        if ',' not in string:
            dep = string
            continue
        if string == '' or string == '\n':
            continue
        string = string.split(',')
        string.insert(4,dep)
        dic[string[2]] = string
        last_names.append(string[2])
    
    except EOFError:
        break
    
last_names.sort()

for names in last_names:
   print(f"----------------------------------------\n{dic[names][0]} {dic[names][1]} {dic[names][2]}\n{dic[names][3]}\nDepartment: {dic[names][4]}\nHome Phone: {dic[names][5]}\nWork Phone: {dic[names][6]}\nCampus Box: {dic[names][7]}")