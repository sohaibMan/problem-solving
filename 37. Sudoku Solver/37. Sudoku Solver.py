# 37. Sudoku Solver
from typing import List


class Solution:
    """
          Do not return anything, modify board in-place instead.
     """
    def solveSudoku(self, board: List[List[str]]) -> None:
            for i in range(0, 9):
                for j in range(0, 9):
                    if board[i][j] == '.':
                        for k in range(1, 10):
                            if Solution.isPossible(i, j, str(k), board):
                                board[i][j] = str(k)
                                # board[i][j].replace(str(k))
                                self.solveSudoku(board)
                                board[i][j] = '.'
                        return
        # print(board)

    def isPossible(x, y, n, board: List[List[str]]) -> bool:
        for i in range(0, 9):
            if board[i][y] == n:
                return False
        for i in range(0, 9):
            if board[x][i] == n:
                return False
        x0 = (x // 3) * 3
        y0 = (y // 3) * 3
        for i in range(0, 3):
            for j in range(0, 3):
                if board[x0 + i][y0 + j] == n:
                    return False
        return True

#
# solution = Solution.cpp()
# grid = [["5", "3", ".", ".", "7", ".", ".", ".", "."], ["6", ".", ".", "1", "9", "5", ".", ".", "."],
#         [".", "9", "8", ".", ".", ".", ".", "6", "."], ["8", ".", ".", ".", "6", ".", ".", ".", "3"],
#         ["4", ".", ".", "8", ".", "3", ".", ".", "1"], ["7", ".", ".", ".", "2", ".", ".", ".", "6"],
#         [".", "6", ".", ".", ".", ".", "2", "8", "."], [".", ".", ".", "4", "1", "9", ".", ".", "5"],
#         [".", ".", ".", ".", "8", ".", ".", "7", "9"]]
#
# solution.solveSudoku(grid)
