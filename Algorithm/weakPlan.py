def twoListsHaveOneCommonElement(list1, list2):
    for i in list1:
        if i in list2:
            return True
    return False

def doDistincsExistInList(list1, list2):
    firstDistict = False
    for i in list1:
        if i not in list2:
            firstDistict = True
            break
    if not firstDistict:
        return False
    for i in list2:
        if i not in list1:
            return True
    return False

totalActivities = int(input())
weak = [
    'Monday',
    'Tuesday',
    'Wednesday',
    'Thursday',
    'Friday',
    'Saturday',
    'Sunday'
]
activities = [
    [],
    [],
    [],
    [],
    [],
    [],
    []
]

for _ in range(7):
    line = input().split()
    index = weak.index(line[0])
    for i in range(2, len(line)):
        activities[index].append(int(line[i]))

commonPairs = []

for i in range(7):
    for j in range(i + 1, 7):
        if twoListsHaveOneCommonElement(activities[i], activities[j]):
            commonPairs.append([weak[i], weak[j]])

minDistance = 10

for i in commonPairs:
    first, second = i[0], i[1]
    validPair = doDistincsExistInList(activities[weak.index(first)], activities[weak.index(second)])
    if validPair:
        minIndex = min(weak.index(first), weak.index(second))
        maxIndex = max(weak.index(first), weak.index(second))
        minDistanceTemp = min(7 + minIndex - maxIndex, abs(weak.index(first) - weak.index(second)))
        if minDistanceTemp < minDistance:
            minDistance = minDistanceTemp

if minDistance > 7:
    print(-1)
else:
    print(minDistance)