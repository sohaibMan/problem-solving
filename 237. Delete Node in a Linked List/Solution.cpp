/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
           ListNode *dummy_head = node;// this is not the tail
    // we must shift all the values to the right
    while (dummy_head!=nullptr && dummy_head->next != nullptr) {
        dummy_head->val = dummy_head->next->val;
        if (dummy_head->next->next == nullptr) {
            dummy_head->next = nullptr;
        }
        dummy_head = dummy_head->next;
    }
    free(dummy_head);
    }
};
