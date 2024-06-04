n = int(input())
permutation = list(map(int, input().split()))
dp = []
for i in range(n):
    low, high = 0, len(dp)
    while low < high:
        mid = (low + high) // 2
        if dp[mid] < permutation[i]:
            low = mid + 1
        else:
            high = mid
    if low == len(dp):
        dp.append(permutation[i])
    else:
        dp[low] = permutation[i]

print(len(dp))