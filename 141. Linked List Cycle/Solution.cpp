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
    bool hasCycle(ListNode *head) {
            if (head == nullptr)return false;
    // brute force for each node count the number of nodes point to the current node ; if one count is bigger than one
    // return true otherwise returns false
    ListNode *fast = head;
    ListNode *slow = head;
    while (fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        slow = slow->next;


        // At the point if fast and slow are at same address
        // this means linked list has a cycle in it.
        if (fast == slow)
            return true;
    }

    // if traversal reaches to NULL this means no cycle.
    return false;
        
    }
};
