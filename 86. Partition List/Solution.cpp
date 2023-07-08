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
public:
    ListNode* partition(ListNode* head, int x) {
         if (head == nullptr || head->next == nullptr)return head;
    ListNode *last_left = nullptr, *last_right = nullptr, *first_right = nullptr, *first_left, *dummy_head = head;// o(1) space

    while (dummy_head != nullptr) {
        if (dummy_head->val >= x) {
            if (last_right != nullptr) {
                last_right->next = dummy_head;
            } else {
                first_right = dummy_head;
            }
            last_right = dummy_head;
        } else {
            if (last_left != nullptr) {
                last_left->next = dummy_head;
            } else {
                first_left = dummy_head;
            }
            last_left = dummy_head;
        }
        dummy_head = dummy_head->next;

    }
      if (last_right != nullptr) {
        last_right->next = nullptr;
    }
    if (last_left == nullptr)return first_right;
    last_left->next = first_right;
    return first_left;

    }
};
