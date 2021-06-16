

def search(index):
    global specs, assigend, adj, n

    if index == n+1:
        return True

    for i in range(4):
        
        flag = True
        for k in adj[index]:
            if k in specs[i]:
                flag = False
                break
        
        if flag:
            assigend[index] = i+1
            specs[i].add(index)
            if search(index+1):
                return True
            else:
                assigend[index] = 0
                specs[i].remove(index)
    
    return False


specs = [set() for i in range(4)]


if __name__ == '__main__':

    n = int(input())

    assigend = [0 for i in range(n+1)]
    adj = [set() for i in range(n+1)]

    while True:
        try:
            a, b = map(int , input().split('-'))
            adj[a].add(b)
            adj[b].add(a)
        except EOFError:
            break

    
    search(1)

    for i in range(1, len(assigend)):
        print(i, assigend[i])
