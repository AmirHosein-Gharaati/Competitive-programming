

while True:

    data, usage = map(int, input().split())

    if data == usage == 0:
        break

    temp1 = data*30 + usage*40
    temp2 = data*35 + usage*30
    temp3 = data*40 + usage*20

    result = min(temp1, min(temp2, temp3))

    print(result)