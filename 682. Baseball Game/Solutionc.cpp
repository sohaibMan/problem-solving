class Solution {
public:
int calPoints(vector<string> &operations) {
    stack<int> history;
    for (const string &operation: operations) {
        try {
            int value = stoi(operation);
            history.push(value);
        }
        catch (...) {

            if (operation == "+") {
                int prv_1 = history.top();
                history.pop();
                int prv_2 = history.top();
                history.push(prv_1);
                history.push(prv_1 + prv_2);
            } else if (operation == "D") {
                int prv_1 = history.top();
                history.push(2 * prv_1);
            } else if (operation == "C") {
                history.pop();
            }
        }
    }
    int score = 0;
    while (!history.empty()) {
        score += history.top();
        history.pop();
    }
    return score;
}
};
