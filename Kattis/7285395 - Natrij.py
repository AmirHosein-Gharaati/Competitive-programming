def convert_to_time(minute):
    lis = [0, 0, 0]

    lis[0] = str(minute // 3600)
    if len(lis[0]) == 1:
        lis[0] = '0' + lis[0]

    minute %= 3600

    lis[1] = str(minute // 60)
    if len(lis[1]) == 1:
        lis[1] = '0' + lis[1]


    minute %= 60
    lis[2] = str(minute)
    if len(lis[2]) == 1:
        lis[2] = '0' + lis[2]

    return ':'.join(lis)





time_one = list(map(int, input().split(':')))
time_two = list(map(int, input().split(':')))

time_one = (time_one[0]*3600) + (time_one[1]*60) + (time_one[2])
time_two = (time_two[0]*3600) + (time_two[1]*60) + (time_two[2])

temp = 0
if time_one > time_two :
    temp = (3600*24) - abs(time_one-time_two)
elif time_one == time_two:
    temp = (3600*24)
else:
    temp = time_two - time_one

print(convert_to_time(temp))
