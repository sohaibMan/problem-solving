class MinStack {
    stack<int> main_stack;
    stack<int> min_stack;
public:


    void push(int val) {
        int min_top = min_stack.empty() ? val : min_stack.top();
        int min_value = min_top > val ? val : min_top;
        min_stack.push(min_value);
        main_stack.push(val);
    }

    void pop() {
        min_stack.pop();
        main_stack.pop();
    }

    int top() {
        return main_stack.top();
    }

    int getMin() {
        return min_stack.top();
    }
};
