//
// Created by sohaib on 5/1/23.
//
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
    string result;
    vector<char> v= {};
    int fact_result{};


    int fact(int n) {
        if (n <= 1)return 1;
        return n * fact(n - 1);
    }


    void getPermutationHelper(int n, int k) {
        if (this->v.empty())return;
        // calculate the size of the block
        // this->fact_result=this->fact_result/n;
        int block_size = this->fact(n);
        // calculate the indice of the
        int indice = (k - 1) / block_size;
        result += this->v[indice];
        this->v.erase(this->v.begin() + indice);
        // this->fact_result=this->fact_result/n;
        getPermutationHelper(n-1, k - block_size * indice);
    }

public:
    string getPermutation(int n, int k) {
        if (n == 0)return "";
        this->fact_result = fact(n - 1);
        char c='1';
        for (int i = 1; i <= n; ++i) {
            v.push_back(c++);
        }

        this->getPermutationHelper(n-1, k);
        return this->result;
    }
};

int main() {
    Solution s;
    cout << s.getPermutation(4, 9);
    return 0;
}