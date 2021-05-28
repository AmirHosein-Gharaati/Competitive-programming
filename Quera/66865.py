def rec(index,prev_state):
    global n, numbers, ascending, descending
    
    if index == n:
        if (descending == 1 or ascending == 1) or (descending == ascending == 0):
            return 'Yes'
        else:
            return 'No'
    
    if  numbers[index-1] > numbers[index] :
        if prev_state == 'ascending' and descending == 1:
            return 'No'
        else:
            descending = 1
            return rec(index+1, 'descending')
        
    elif numbers[index-1] < numbers[index]:
        if prev_state == 'descending' and ascending == 1:
            return 'No'
        else:
            ascending = 1
            return rec(index+1, 'ascending')
    else:
        if prev_state != None and (ascending == descending == 1):
            return 'No'
                
        return rec(index+1, prev_state)


n = int(input())
numbers = list(map(int, input().split()))
ascending = 0
descending = 0
if len(numbers) == 1:
    print('Yes')
else:
    print(rec(1,None))
