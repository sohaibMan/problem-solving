#include <iostream>
#include <vector>

using namespace std;

//Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

//Integers in each row are sorted in ascending from left to right.
//Integers in each column are sorted in ascending from top to bottom.


//Integers in each row are sorted in ascending from left to right.
//Integers in each column are sorted in ascending from top to bottom.

class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        return searchMatrix(matrix, target, 0, int(matrix[0].size()) - 1);
    }

private:
    bool searchMatrix(vector<vector<int>> &matrix, int target, int i, int j) {
        if (i < 0 || j < 0 || i == matrix.size() || j == matrix[0].size())return false;
        if (matrix[i][j] == target)return true;
        else if (target > matrix[i][j]) {
            // the value is sure in all i,j with i>start =>i=start+1
            // the value is sure in all i,j with j>end =>j=end+1
            return searchMatrix(matrix, target, i + 1, j);

        } else {
            // the value is sure in all i,j with i<start =>i=start-1
            // the value is sure in all i,j with j<end =>j=end-1
            return searchMatrix(matrix, target, i, j - 1);
        }
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
