t = int(input())
while t:
    n, l, r = input().split()
    n, l, r = int(n), int(l), int(r)
    leftSocks = input().split()
    for i in range(n):
        leftSocks[i] = int(leftSocks[i])
    leftSocks = list(leftSocks)
    rightSocks = leftSocks[l: n]
    leftSocks = leftSocks[0:l]
    leftSocks.sort()
    rightSocks.sort()
    lPtr, rPtr = 0, 0
    cost = 0
    while lPtr < len(leftSocks) and rPtr < len(rightSocks):
        if leftSocks[lPtr] == rightSocks[rPtr]:
            leftSocks.pop(lPtr)
            rightSocks.pop(rPtr)
        if leftSocks[lPtr] < rightSocks[rPtr]:
            lPtr += 1
        else:
            rPtr += 1
    dicLeftSocks = {}
    dicRightSocks = {}
    last = 0
    for item in leftSocks[:]:
        if item == leftSocks[len(leftSocks) - 1]:
            last = item
        if item in dicLeftSocks and dicLeftSocks[item] == 2:
            cost += 1
            del dicLeftSocks[item]
        if item not in dicLeftSocks.keys():
            dicLeftSocks[item] = 1
        else:
            dicLeftSocks[item] += 1
        leftSocks.remove(item)
    if last in dicLeftSocks and dicLeftSocks[last] == 2:
        cost += 1
        del dicLeftSocks[last]
    for item in rightSocks[:]:
        if item == rightSocks[len(rightSocks) - 1]:
            last = item
        if item in dicRightSocks and dicRightSocks[item] == 2:
            cost += 1
            del dicRightSocks[item]
        if item not in dicRightSocks.keys():
            dicRightSocks[item] = 1
        else:
            dicRightSocks[item] += 1
        rightSocks.remove(item)
    if last in dicRightSocks and dicRightSocks[last] == 2:
        cost += 1
        del dicRightSocks[last]
    print(dicLeftSocks, dicRightSocks)
    cost += min(len(dicLeftSocks), len(dicRightSocks)) + (max(len(dicLeftSocks), len(dicRightSocks)) - min(len(dicLeftSocks), len(dicRightSocks)))
    print(cost)
    t -= 1