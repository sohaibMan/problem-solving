#include <iostream>


using namespace std;
template<typename T>
struct ListNode {
    T data;
    struct ListNode *next;
};

//typedef struct ListNode<int> iListNode;

template<typename T>
ListNode<T> *NewListNode(T data) {
    auto *node = static_cast<ListNode<T> *>(malloc(sizeof(ListNode<T>)));
    node->next = nullptr;
    node->data = data;
    return node;
}

template<typename T>
class Stack {
    ListNode<T> *head;


private:
    void clean(ListNode<T> *current) {
        if (current == nullptr)return;
        clean(current->next);
        free(current);
    }

public:


    ~Stack() {
        clean();
    };

    void push(T data) {
        // last in first out (insert a node before the head)
        ListNode<T> *node = NewListNode<T>(data);// o(1)
        node->next = head;
        head = node;
    }

    T pop() {
        // last in first out (we must remove the head) // o(1)
        if (empty())throw invalid_argument("underflow");
        ListNode<T> *tmp = head->next;
        T data = head->data;
        free(head);
        head = tmp;
        return data;
    }

    T top() {
        if (head == nullptr)throw invalid_argument("underflow");
        return head->data;// o(1)
    }

    bool empty() {
        return head == nullptr;// o(1)
    }

};

bool isValid(string s) {
//    20. Valid Parentheses
    if (s.empty())return true;
    auto *stack = new Stack<char>();
    for (const char &item: s) {
        if (item == '(')stack->push('(');
        else if (item == '[')stack->push('[');
        else if (item == '{')stack->push('{');
        else if (stack->empty())return false;
        else if (item == ']') {
            char c = stack->top();
            stack->pop();
            if (c != '[')return false;
        } else if (item == '}') {
            char c = stack->top();
            stack->pop();
            if (c != '{')return false;
        } else if (item == ')') {
            char c = stack->top();
            stack->pop();
            if (c != '(')return false;
        }
    }
    return stack->empty();
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

