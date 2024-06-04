n = int(input())

listLens = {}
listOrder = []

for _ in range(n):
    lst = list(map(int, input().split()))
    listOrder.append(lst)
    if len(lst) not in listLens:
        listLens[len(lst)] = []
    if lst not in listLens[len(lst)]:
        listLens[len(lst)].append(lst)

keys = list(listLens.keys())
keys.sort()

partialSum = {key: 0 for key in keys}
for i in range(len(keys)):
    if i == 0:
        continue
    partialSum[keys[i]] = partialSum[keys[i - 1]] + len(listLens[keys[i - 1]])

for key in keys:
    listLens[key] = sorted(listLens[key])

string = ''
for item in listOrder:
    string += chr(65 + ((listLens[len(item)].index(item) + partialSum[len(item)]) % 26))

print(string)