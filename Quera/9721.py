# Python program for implementation of MergeSort 
def mergeSort(arr):
    global count
    if len(arr) >1: 
        mid = len(arr)//2 # Finding the mid of the array 
        L = arr[:mid] # Dividing the array elements 
        R = arr[mid:] # into 2 halves 

        mergeSort(L) # Sorting the first half 
        mergeSort(R) # Sorting the second half 

        i = j = k = 0
        # Copy data to temp arrays L[] and R[] 
        while i < len(L) and j < len(R): 
            if L[i] <= R[j]: 
                arr[k] = L[i]
                if i-k>0:
                    count+=(i-k) 
                i+= 1
            else: 
                arr[k] = R[j] 
                if j+mid-k>0:
                    count+=(j+mid-k)
                j+= 1
            k+= 1
        
        # Checking if any element was left 
        while i < len(L): 
            arr[k] = L[i] 
            i+= 1
            k+= 1
        
        while j < len(R): 
            arr[k] = R[j] 
            j+= 1
            k+= 1


n = int(input())
count = 0
arr = [int(input()) for i in range(n)]
mergeSort(arr)
print(count%100000)