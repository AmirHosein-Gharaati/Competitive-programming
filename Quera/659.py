def DeleteLeft():
    global books
    books.pop(0)

def AddLeft(name):
    global books
    books.insert(0,name)

def AddRight(name):
    global books
    books.append(name)

n = int(input())

books = [input() for i in range(n)]

while 1:
    command = input()
    if command == 'Exit':
        break
    if command == 'DeleteLeft':
        DeleteLeft()
    elif command == 'AddLeft':
        name = input()
        AddLeft(name)
    elif command == 'AddRight':
        name = input()
        AddRight(name)
    
print(len(books))
for i in books:
    print(i)
    
    
    
    
    
    
    
    