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
    private:
    void removeElements(ListNode **head, int val) {
    if (head == nullptr || (*head) == nullptr || ((*head)->next == nullptr && (*head)->val == val)) {
        // free(*head);
        *head = nullptr;
        return;
    } else if ((*head)->val == val) {
        ListNode *tmp = (*head)->next;
        // free(*head);
        (*head) = tmp;
        return removeElements(head, val);
    } else if ((*head)->next != nullptr && (*head)->next->val == val) {
        ListNode *tmp = (*head)->next;
        (*head)->next = (*head)->next->next;
        // free(tmp);
        return removeElements(head, val);
    }
    removeElements(&(*head)->next, val);
}
public:
 ListNode *deleteDuplicates(ListNode *head) {
    if (head == nullptr)return nullptr;
    ListNode *dummy_head = head;
    while (dummy_head != nullptr) {
        removeElements(&dummy_head->next, dummy_head->val);
        dummy_head = dummy_head->next;
    }
    return head;
}
};
