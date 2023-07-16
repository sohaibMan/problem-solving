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
    ListNode *detectCycle(ListNode *head) {
         // o(n)
    // let D the distance of nodes until the start of the node
    // let K the distance of nodes from the start to the node when fast=slow
    // and let's assume that c is length of the list
    // and i and j are integers
    // (2) fast will be at D + K + i * C with 2 * N nodes in total
    // (1) slow will be at D + K + j * C with N nodes in total
    // 2* (1)=(2) => 2D + 2K + 2JC=D+K+iC
    // D + k= cte * C
    // D= cte * c - k
    // ==> we will reach our start node after D nodes from the head  ( D nodes from the start will stop at our start node)
    // ==> we will reach our start node after D nodes from the current position of fast pointer
    // ==> D is unknown, but we know that two pointers one from the start and other from the current position will
    // meetup after D iteration (they will meetup)
    ListNode *fast = head;
    ListNode *slow = head;
    bool isCyclic = false;
    while (fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow) {
            isCyclic = true;
            break;
        }
    }
    if (!isCyclic)return nullptr;
    // the list is cyclic now
    fast = head;
    while (fast != slow) {
        slow = slow->next;
        fast = fast->next;
    }
    return fast;
        
    }
};
