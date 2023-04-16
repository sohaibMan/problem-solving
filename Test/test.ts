
// Definition for singly - linked list.
class ListNode {
    val: number
    next: ListNode | null
    constructor(val?: number, next?: ListNode | null) {
        this.val = (val === undefined ? 0 : val)
        this.next = (next === undefined ? null : next)
    }
}

function addTwoNumbers(l1: ListNode | null, l2: ListNode | null) {

    // on consider que l1 et l2 sont de meme taille 

    if (l1 === null || l2 === null) return null;
    const curry = l1.val + l1.val >= 10;
    const l = new ListNode(l1.val + l2.val + (curry ? 0 : -10));
    l1.next = addTwoNumbers(l1.next, l2.next);
    return l;


}

const l1 = new ListNode(2)
const node1 = new ListNode(4);
l1.next = node1;
const node2 = new ListNode(3);
node1.next = node2;
node2.next = null;

const l2 = new ListNode(5)
const node3 = new ListNode(6);
l2.next = node3;
const node4 = new ListNode(4);
node3.next = node4;
node4.next = null;

console.log(addTwoNumbers(l1, l2));
