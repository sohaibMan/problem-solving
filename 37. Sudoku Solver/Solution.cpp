class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(0, 0, board);
    }

private:
    bool solve(int i, int j, vector<vector<char>>& board) {
        if (i == 9) return true;
        if (j == 9) return solve(i+1, 0, board);
        if (board[i][j] != '.') return solve(i, j+1, board);
        for (char c = '1'; c <= '9'; ++c) {
            if (isValid(i, j, c, board)) {
                board[i][j] = c;
                if (solve(i, j+1, board)) return true;
                board[i][j] = '.';
            }
        }
        return false;
    }

    bool isValid(int i, int j, char c, vector<vector<char>>& board) {
        for (int k = 0; k < 9; ++k)
            if (board[i][k] == c || board[k][j] == c || board[(i/3)*3+k/3][(j/3)*3+k%3] == c)
                return false;
        return true;
    }
};