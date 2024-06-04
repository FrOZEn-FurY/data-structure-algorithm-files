board = []
m, n, a = input().split()
m, n, a = int(m), int(n), int(a)

def getMaximumLengthOfValue(type, rowIndex, colIndex, value):
    length = 0
    while 0 <= rowIndex < m and 0 <= colIndex < n and board[rowIndex][colIndex] == value:
        length += 1
        if type == 'row':
            colIndex += 1
        elif type == 'col':
            rowIndex += 1
        elif type == 'rdiag':
            rowIndex += 1
            colIndex += 1
        elif type == 'ldiag':
            rowIndex += 1
            colIndex -= 1
    return length
        
for i in range(m):
    board.append(list(map(int, input().split())))

maxScore = {i: 0 for i in range(1, a + 1)}

for j in range(m):
    for k in range(n):
        maxScore[board[j][k]] = max(maxScore[board[j][k]], getMaximumLengthOfValue('row', j, k, board[j][k]),
                                    getMaximumLengthOfValue('col', j, k, board[j][k]),
                                    getMaximumLengthOfValue('rdiag', j, k, board[j][k]),
                                    getMaximumLengthOfValue('ldiag', j, k, board[j][k]))

for i in range(1, a + 1):
    print(maxScore[i], end=' ' if i < a else '\n')