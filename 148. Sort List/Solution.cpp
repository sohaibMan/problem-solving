#include "iostream"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
private:
    static ListNode *getMiddleNode(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head->next;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    static ListNode *mergeList(ListNode *L1, ListNode *L2) {

        ListNode *dummyHead = new ListNode(), *tail;
        tail=dummyHead;

        while (L1 != nullptr && L2 != nullptr) {
            if (L1->val < L2->val) {
                tail->next = L1;
                L1 = L1->next;
            } else {
                tail->next = L2;
                L2 = L2->next;
            }
            tail = tail->next;
        }

        if (L1 != nullptr) {
            tail->next = L1;
        }

        if (L2 != nullptr) {
            tail->next = L2;
        }

        return dummyHead->next;
    }

public:
    ListNode *sortList(ListNode *head) {
        // if the list contain zero or one node (return the head of the node which null of the head)
        if (head == nullptr || head->next == nullptr)
            return head;
        // split the current list to two halves right and left
        ListNode *left = head;
        ListNode *right = Solution::getMiddleNode(head);
        ListNode *tmp = right->next;
        right->next = nullptr;
        right = tmp;
        left = this->sortList(left);
        right = this->sortList(right);
        return Solution::mergeList(left, right);


    }
};

int main() {
    ListNode *head = new ListNode(4);
    ListNode *node1 = new ListNode(2);
    ListNode *node2 = new ListNode(1);
    ListNode *node3 = new ListNode(3);
    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    Solution solution;
    ListNode *sortedList = solution.sortList(head);


    while (sortedList != nullptr) {
        std::cout << sortedList->val << " ";
        sortedList = sortedList->next;
    }
    return 0;
}