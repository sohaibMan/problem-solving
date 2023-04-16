
//  Definition for singly - linked list.
class ListNode {
    val: number
    next: ListNode | null
    constructor(val?: number, next?: ListNode | null) {
        this.val = (val === undefined ? 0 : val)
        this.next = (next === undefined ? null : next)
    }
}
function mergeTwoLists(list1: ListNode | null, list2: ListNode | null): ListNode | null {

    if (list1 === null && list2 === null) return null;
    if (list1 === null && list2 !== null) {
        return list2;
    }
    if (list2 === null && list1 !== null) {
        return list1;
    }

    const newNode = new ListNode();
    // @ts-ignore
    if (list1.val < list2.val) {
        // @ts-ignore
        newNode.val = list1.val;
        // @ts-ignore
        newNode.next = mergeTwoLists(list1.next, list2);
    }
    else {
        // @ts-ignore
        newNode.val = list2.val;
        // @ts-ignore
        newNode.next = mergeTwoLists(list1, list2.next);
    }
    return newNode;


};


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

console.log(mergeTwoLists(l1, l2));
