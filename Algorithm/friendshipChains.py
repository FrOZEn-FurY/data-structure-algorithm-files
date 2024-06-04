n = int(input())

friends = {}

for _ in range(n):
    name, friend = input().split()
    if name not in friends:
        friends[name] = []
    if friend not in friends:
        friends[friend] = []
    friends[name].append(friend)
    friends[friend].append(name)

target = input()
frindsOfFriends = set()

for friend in friends[target]:
    friendList = friends[friend]
    appendable = [fr for fr in friendList if fr != target]
    frindsOfFriends.update(appendable)

frindsOfFriends = sorted(frindsOfFriends)

print(f'Friends of friends of {target}: {frindsOfFriends}')
