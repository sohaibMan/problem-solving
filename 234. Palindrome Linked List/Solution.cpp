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
  bool isPalindrome(ListNode *head) {
    // O(n) time and O(1) space
    ListNode *slow = head;
    ListNode *fast = head;
    // O(n) operation
    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    // n/2 operations (this is will mutate the list !!!)
    reverse_list(&slow);
    fast = head;
    while (slow != nullptr) {
        if (fast->val != slow->val)return false;
        fast = fast->next;
        slow = slow->next;
    }
    return true;

}
};
