void removeElements(ListNode **head, int val) {
    if (head == nullptr || (*head) == nullptr || ((*head)->next == nullptr && (*head)->val == val)) {
        free(*head);
        *head = nullptr;
        return;
    } else if ((*head)->val == val) {
        ListNode *tmp = (*head)->next;
        free(*head);
        (*head) = tmp;
        return removeElements(head, val);
    } else if ((*head)->next != nullptr && (*head)->next->val == val) {
        ListNode *tmp = (*head)->next;
        (*head)->next = (*head)->next->next;
        free(tmp);
        return removeElements(head, val);
    }
    removeElements(&(*head)->next, val);
}

ListNode *removeElements(ListNode *head, int val) {
    ListNode *dummy_head = head;
    removeElements(&dummy_head, val);
    return dummy_head;
}
