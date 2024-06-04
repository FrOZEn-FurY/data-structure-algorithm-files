base_board = [
    '  1   2   3 ',
    '    |   |   ',
    '1   |   |   ',
    '    |   |   ',
    '----+---+---',
    '    |   |   ',
    '2   |   |   ',
    '    |   |   ',
    '----+---+---',
    '    |   |   ',
    '3   |   |   ',
    '    |   |   ',
    '----+---+---'
]

board = base_board.copy()
filled = [
    ['', '', ''],
    ['', '', ''],
    ['', '', '']
]
filledCntr = 0

def checkWin(mark, row, col):
    away1 = (col + 1) % 3
    away2 = (col + 2) % 3
    if filled[row][col] == filled[row][away1] == filled[row][away2] == mark:
        return True
    away1 = (row + 1) % 3
    away2 = (row + 2) % 3
    if filled[row][col] == filled[away1][col] == filled[away2][col] == mark:
        return True
    if row == col == 1:
        if filled[0][0] == filled[1][1] == filled[2][2] == mark:
            return True
        if filled[0][2] == filled[1][1] == filled[2][0] == mark:
            return True
    if (row == 0 and col == 0) or (row == 2 and col == 2):
        if filled[1][1] == filled[0][0] == filled[2][2] == mark:
            return True
    if (row == 0 and col == 2) or (row == 2 and col == 0):
        if filled[1][1] == filled[0][2] == filled[2][0] == mark:
            return True
    return False

player_1 = input("Player 1 please choose a name (default player 1): ")
if player_1 == "":
    player_1 = "player 1"
player_2 = input("Player 2 please choose a name (default player 2): ")
if player_2 == "":
    player_2 = "player 2"

p1Mark = ""
p2Mark = ""
while p1Mark == "":
    inp = input(f"{player_1} please choose your mark (X or O): ")
    if inp != "X" and inp != "O":
        print("Inavlid input.")
        continue
    p1Mark = inp
p2Mark = 'O' if p1Mark == 'X' else 'X'

turn = 0
while True:
    if filledCntr == 9:
        print("Draw.")
        inp = input("Would you like to play again? (Y/N): ")
        if inp == 'Y' or inp == 'y':
            filled = [
                ['', '', ''],
                ['', '', ''],
                ['', '', '']
            ]
            board = base_board.copy()
            turn = 0
            filledCntr = 0
            continue
        else:
            print("Well then, good luck!")
            break
    for line in board:
        print(line)
    try:
        row, col = input(f"{'X' if turn % 2 == 0 else 'O'} Turn, Please choose a row and a column in order: ").split()
    except ValueError:
        print('Two values seprated with a space must be given.')
        continue
    if not row.isdigit() or not col.isdigit():
        print("Inavlid input. Two number which are row number and column number must be given.")
        continue
    if int(row) > 3 or int(row) < 1 or int(col) > 3 or int(col) < 1:
        print("Row and column you enter must be between number 1, 2 and 3.")
        continue
    if filled[int(row) - 1][int(col) - 1] != '':
        print("That spot is already taken.")
        continue
    filled[int(row) - 1][int(col) - 1] = 'X' if turn % 2 == 0 else 'O'
    board[2 + (4 * (int(row) - 1))] = board[2 + (4 * (int(row) - 1))][:2 + (4 * (int(col) - 1))] + ('X' if turn % 2 == 0 else 'O') + board[2 + (4 * (int(row) - 1))][2 + (4 * (int(col) - 1)) + 1:]
    filledCntr += 1
    if checkWin('X' if turn % 2 == 0 else 'O', int(row) - 1, int(col) - 1):
        turnMark = 'X' if turn % 2 == 0 else 'O'
        if p1Mark == turnMark:
            print(f"{player_1} has won the game.")
        else:
            print(f"{player_2} has won the game.")
        inp = input("Would you like to play again? (Y/N): ")
        if inp == 'Y' or inp == 'y':
            filled = [
                ['', '', ''],
                ['', '', ''],
                ['', '', '']
            ]
            board = base_board.copy()
            turn = 0
            filledCntr = 0
            continue
        else:
            print("Well then, good luck!")
            break
    turn = 0 if turn == 1 else 1


