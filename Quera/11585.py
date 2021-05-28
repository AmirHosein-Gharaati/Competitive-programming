def SubArraySum(arr, n ): 
    result = 0
  
    # computing sum of subarray  
    # using formula 
    for i in range(0, n): 
        result += (arr[i] * (i+1) * (n-i)) 
  
    # return all subarray sum 
    return result


n = int(input())
lis = list(map(int,input().split()))
print(SubArraySum(lis,n))
