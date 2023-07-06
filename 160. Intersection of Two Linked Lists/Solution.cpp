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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
           // the reason of this function is to find the intersection node of two nodes that are different
    if (headA == nullptr || headB == nullptr)return nullptr;
    // first way is using a hash table
    // space complexity o(n+m)
    // time complexity o(n+m)
    map<ListNode *, int> all_nodes;
    while (headA != nullptr && headB != nullptr) {

        // insert headA  to the nodes
        if (all_nodes.count(headA) == 1)return headA;
        all_nodes.insert({headA, headA->val});
        // check if headB exists
        if (all_nodes.count(headB) == 1)return headB;
        all_nodes.insert({headB, headB->val});

        headA = headA->next;
        headB = headB->next;
    }
    while (headA != nullptr) {

        if (all_nodes.count(headA) == 1)return headA;
        all_nodes.insert({headA, headA->val});
        headA = headA->next;
    }
    while (headB != nullptr) {

        if (all_nodes.count(headB) == 1)return headB;
        all_nodes.insert({headB, headB->val});
        headB = headB->next;
    }
    return nullptr;
    }
};
