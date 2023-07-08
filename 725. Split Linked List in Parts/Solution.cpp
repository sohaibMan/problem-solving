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
    int list_length(ListNode *head) {
    //o(n)
    // recursive solution
    if (head == nullptr)return 0;
    return 1 + list_length(head->next);
}

public:
   
vector<ListNode *> splitListToParts(ListNode *head, int k) {
// split the list into k parts
// lets says the length is called length
// each part will be of length i= l / k;
    int length = list_length(head);// o(n)
    vector<ListNode *> parts;
    // example length is 20 and k=3
    int nodes_length_per_list = length / k;// 6 nodes per each list
    int extra_ones = length % k;// 2 nodes ( first two lists will be of length 7)
    // 7 7 6
    ListNode *dummy_head = head;
    for (int i = 1; i <= k; i++) {
        int list_length = nodes_length_per_list;//7 for i=1 ; 7 for i=2 ; 6 for i=3;
        if (extra_ones != 0) {
            list_length++;
            extra_ones--;
        }
        parts.push_back(dummy_head);// the first node at the list
         if (dummy_head == nullptr) {
            continue;
        }
        list_length--;
        while (list_length != 0) {
            --list_length;
            dummy_head = dummy_head->next;
        }
        ListNode *next = dummy_head->next;
        dummy_head->next = nullptr;
        dummy_head = next;
    }


    return parts;
}
};
