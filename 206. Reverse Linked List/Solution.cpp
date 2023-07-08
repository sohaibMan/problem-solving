//206. Reverse Linked List

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
class Solution {

    void reverse_list(ListNode **head, ListNode *current, ListNode *caller) {
    if (current == nullptr)return;// rethink about that
    if (current->next == nullptr) {
        // that is the tail
        *head = current;
    }
    reverse_list(head, current->next, current);
    current->next = caller;

}

void reverse_list(ListNode **head) {
    reverse_list(head, *head, nullptr);
}
public:
ListNode *reverseList(ListNode *head) {
    ListNode *dummy_head = head;
    reverse_list(&dummy_head);
    return dummy_head;
}
};
