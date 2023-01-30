#!/usr/bin/python3
"""Solves the N-queens puzzle.
Determines all possible solutions to placing N
N non-attacking queens on an NxN chessboard.
Example:
    $ ./101-nqueens.py N
N must be an integer greater than or equal to 4.
Attributes:
    board (list): A list of lists representing the chessboard.
    solutions (list): A list of lists containing solutions.
Solutions are represented in the format [[r, c], [r, c], [r, c], [r, c]]
where `r` and `c` represent the row and column, respectively, where a
queen must be placed on the chessboard.
"""
import sys

def nqueens(n):
    def is_not_under_attack(row, col):
        # checking if there is a queen in the left or right diagonal
        for i, j in zip(range(row, -1, -1), range(col, -1, -1)):
            if board[i][j] == 1:
                return False
        for i, j in zip(range(row, -1, -1), range(col, n)):
            if board[i][j] == 1:
                return False

        return True

    def solve(board, row):
        if row == n:
            result.append(board)
            return

        for col in range(n):
            if is_not_under_attack(row, col):
                board[row][col] = 1
                solve(board, row + 1)
                board[row][col] = 0

    board = [[0] * n for _ in range(n)]
    result = []
    solve(board, 0)
    return result

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)
    try:
        n = int(sys.argv[1])
    except ValueError:
        print("N must be a number")
        sys.exit(1)
    if n < 4:
        print("N must be at least 4")
        sys.exit(1)

    for solution in nqueens(n):
        print(solution)

