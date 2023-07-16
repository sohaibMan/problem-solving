/**
 * Definition for singly-linked list.
 * class ListNode {
 *     val: number
 *     next: ListNode | null
 *     constructor(val?: number, next?: ListNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.next = (next===undefined ? null : next)
 *     }
 * }
 */
var ListNode = /** @class */ (function () {
    function ListNode(val, next) {
        this.val = (val === undefined ? 0 : val);
        this.next = (next === undefined ? null : next);
    }
    return ListNode;
}());
/**
 * Definition for singly-linked list.
 * class ListNode {
 *     val: number
 *     next: ListNode | null
 *     constructor(val?: number, next?: ListNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.next = (next===undefined ? null : next)
 *     }
 * }
 */
function removeNthFromEnd(head, n) {
    var _a;
    if (head === null)
        return null;
    var ptrA = head;
    var ptrB = head;
    for (var i = 1; i <= n; i++) {
        ptrB = ptrB.next;
        // 1<=n<=sz
    }
    if (ptrB === null && ptrA.next === null)
        return null;
    if (ptrB === null)
        return ptrA.next;
    //      we know now that ptrA is with a delay of n steps of ptrB
    while (ptrB.next !== null) {
        ptrB = ptrB.next;
        ptrA = ptrA.next;
    }
    ptrA.next = ((_a = ptrA.next) === null || _a === void 0 ? void 0 : _a.next) || null;
    return head;
}
function printNode(head) {
    var dummyHead = head;
    while (dummyHead) {
        console.log(dummyHead.val);
        dummyHead = dummyHead.next;
    }
}
var head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
var head1 = new ListNode(1, new ListNode(2));
removeNthFromEnd(head1, 1);
printNode(head1);
