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
    ListNode* oddEvenList(ListNode* head) {
    if (head == nullptr || head->next==nullptr)return head;
    ListNode *last_odd = head, *last_even = nullptr, *first_even, *dummy_head = head->next;// o(1) space
    int i = 2;
    while (dummy_head != nullptr) {
        if (i % 2 == 0) {
            if (last_even != nullptr) {
                last_even->next = dummy_head;
            } else {
                first_even = dummy_head;
            }
            last_even = dummy_head;
        } else {
            last_odd->next = dummy_head;
            last_odd = dummy_head;
        }
        dummy_head = dummy_head->next;
        i++;
    }
    last_odd->next = first_even;
    last_even->next = nullptr;
    return head;
   
    }
   
};
