class MinStack {
    stack<int> main_stack;
    stack<int> min_stack;
public:


    void push(int val) {
        if(min_stack.empty() || min_stack.top() >=val ){
            min_stack.push(val);
        }
        main_stack.push(val);
    }

    void pop() {
        if(min_stack.top()==main_stack.top())min_stack.pop();
        main_stack.pop();
    }

    int top() {
        return main_stack.top();
    }

    int getMin() {
        return min_stack.top();
    }
};
