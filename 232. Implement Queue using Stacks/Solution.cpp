class MyQueue {
        stack<int> stack_1, stack_2;
public:
    void push(int x) {
        // o(1)
          while (!stack_1.empty()) {
            stack_2.push(stack_1.top());
            stack_1.pop();
        }

        stack_1.push(x);

        while (!stack_2.empty()) {
            stack_1.push(stack_2.top());
            stack_2.pop();
        }
    }
    
    int pop() {
        int top= stack_1.top();
        stack_1.pop();
        return top;
    }
    
    int peek() {
    return stack_1.top();
        
    }
    
    bool empty() {
          return stack_1.empty(); 
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

