#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

//https://leetcode.com/problems/coin-change/

class Solution {
    unordered_map<int, int> hashmap;
public:
    int min_ignore(int a, int b) {
        if (!a) { return b; };
        if (!b) { return a; };
        return min(a, b);
    }

    int coinChange(vector<int> &coins, int amount) {
        int result = coinChangeHelper(coins, amount);
        if (!result)return -1;
        else return result;
    }

    int coinChangeHelper(vector<int> &coins, int amount) {
        if (hashmap.find(amount) != hashmap.end())return hashmap[amount];

        int answer = NULL;

        if (amount == 0) {
            answer = 0;
        } else {
            for (int coin: coins) {
                if (amount - coin < 0) {
                    //impossible to use this coin with this amount
                    continue;
                }
                int next_answer = coinChangeHelper(coins, amount - coin);
                if (next_answer) {
                    next_answer++;
                }
                answer = min_ignore(answer, next_answer);
            }
            hashmap.insert({amount, answer});
        }


        return answer;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
