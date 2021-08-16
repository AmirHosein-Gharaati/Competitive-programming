

tt = int(input())

for ii in range(tt):

    input()

    indexes = list(map(int, input().split()))
    numbers = input().split()

    nums = len(numbers)*[0]

    for i, index in enumerate(indexes):
        nums[index-1] = numbers[i]
    
    for num in nums:
        print(num)

    if ii != tt-1:
        print()