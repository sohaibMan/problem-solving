#include <iostream>

using namespace std;

class Solution {
public:
    static int titleToNumber(const string& columnTitle) {
        int sum = 0;

        for (char i : columnTitle) {
            int d = i - 'A' + 1;
            sum = sum * 26 + d;
        }


        return sum;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
