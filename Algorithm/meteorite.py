meteorites = list(map(int, input().split()))

cntr = 0
step = 1
while cntr < len(meteorites):
    if meteorites[cntr] < 0 and cntr > 0:
        if meteorites[cntr - 1] > 0 and (abs(meteorites[cntr]) == meteorites[cntr - 1]):
            print(f'step {step}: meteorite with index {cntr - 1} and {cntr} with size {meteorites[cntr - 1]} exploded')
            step += 1
            meteorites.pop(cntr)
            meteorites.pop(cntr - 1)
            print(f'new orbit: {meteorites}')
            cntr = max(cntr - 2, 0)
        elif meteorites[cntr - 1] > 0 and (abs(meteorites[cntr]) > meteorites[cntr - 1]):
            print(f'step {step}: meteorite with index {cntr - 1} with size {meteorites[cntr - 1]} exploded')
            step += 1
            meteorites[cntr] += meteorites[cntr - 1]
            meteorites.pop(cntr - 1)
            print(f'new orbit: {meteorites}')
            cntr = max(cntr - 2, 0)
        elif meteorites[cntr - 1] > 0 and (abs(meteorites[cntr]) < meteorites[cntr - 1]):
            print(f'step {step}: meteorite with index {cntr} with size {meteorites[cntr]} exploded')
            step += 1
            meteorites[cntr - 1] += meteorites[cntr]
            meteorites.pop(cntr)
            print(f'new orbit: {meteorites}')
            cntr = max(cntr - 1, 0)
    cntr += 1

print(f'final orbit: {meteorites}')