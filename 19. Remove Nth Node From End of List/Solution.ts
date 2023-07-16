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

class ListNode {
    val: number
    next: ListNode | null

    constructor(val?: number, next?: ListNode | null) {
        this.val = (val === undefined ? 0 : val)
        this.next = (next === undefined ? null : next)
    }
}

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

function removeNthFromEnd(head: ListNode | null, n: number): ListNode | null {
    if (head === null) return null;
    let ptrA = head;
    let ptrB = head;

    for (let i = 1; i <= n; i++) {
        ptrB = ptrB.next;
        // 1<=n<=sz
    }
    if(ptrB===null && ptrA.next===null)return null;
    if(ptrB===null)return ptrA.next;

    //      we know now that ptrA is with a delay of n steps of ptrB
    while (ptrB.next !== null) {
        ptrB = ptrB.next;
        ptrA = ptrA.next;
    }

    ptrA.next = ptrA.next?.next || null;
    return head;
}
function printNode(head: ListNode) {
    let dummyHead = head;
    while (dummyHead) {
        console.log(dummyHead.val)
        dummyHead = dummyHead.next;
    }
}


let head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))))
let head1 = new ListNode(1, new ListNode(2))
removeNthFromEnd(head1, 1);
printNode(head1)