#include <iostream>

using namespace std;
class Solution {
public:
    int lengthOfLastWord(const string &s) {
        int length = 0;
        for (int i = int(s.length()) - 1; i >= 0; i--) {
            if (s.at(i) != ' ') {
                length++;
            } else if (length > 0) {
                return length;
            }
        }
        return length;
    }
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
