#include <iostream>
#include <vector>

using namespace std;

class Solution;


class Solution {
    static int max_sub_problems(const vector<int> &L, const vector<vector<int>> &nums, const int k) {

        int max_value = 0;
        for (int i = 0; i < k; ++i) {
            if (nums[i][1] < nums[k][0] && L[i] > max_value) {
                max_value = L[i];
            }
        }

        return max_value;

    }

    static int max_arr(const vector<int> &vec, int length) {
        int max = 0;
        for (int i = 0; i < length; ++i) {
            if (vec[i] > max)max = vec[i];

        }
        return max;
    }

public:
    int findLongestChain(vector<vector<int>> &pairs) {
        int size = int(pairs.size());
        vector<int> L;
        L.reserve(size);
        // at least one per every  increasing subsequence
        // the longest increasing subsequence(LIS)
        for (int i = 0; i < size; ++i) {
            L.push_back(1);
        }

        for (int k = 0; k < size; k++) {
            L[k] = 1 + max_sub_problems(L, pairs, k);

        }

        return max_arr(L, size);
    }
};

int main() {

    vector<vector<int>> pairs = {{1, 2},
                                 {7, 8},
                                 {4, 5}};

    Solution solution;
    cout << solution.findLongestChain(pairs) << endl;

    return 0;
}
