class MyStack {
    queue<int> queue1, queue2;
    // push(1) push(2) push(3) ==> 3 2 1
public:
    MyStack() {

    }

    void push(int x) {
        while (!queue1.empty()) {
            queue2.push(queue1.front());
            queue1.pop();
        }
        queue1.push(x);
        while (!queue2.empty()) {
            queue1.push(queue2.front());
            queue2.pop();
        }
    }

    int pop() {
        int i = queue1.front();
        queue1.pop();
        return i;
    }

    int top() {
        return queue1.front();
    }

    bool empty() {
        return queue1.empty();
    }
};
