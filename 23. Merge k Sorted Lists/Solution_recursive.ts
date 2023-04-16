
//  Definition for singly - linked list.
class ListNode {
    val: number
    next: ListNode | null
    constructor(val?: number, next?: ListNode | null) {
        this.val = (val === undefined ? 0 : val)
        this.next = (next === undefined ? null : next)
    }
}
function mergeKLists(lists: Array<ListNode | null>): ListNode | null {
    // all is null
    if (lists.filter(list => list === null).length === lists.length) return null;
    const emptyListIndices: number[] = [];
    lists.forEach((list, i) => {
        if (list === null) emptyListIndices.push(i);
    })
    lists = lists.filter((list, i) => !emptyListIndices.includes(i))
    // lists doesn't have any null list
    let minListIndice = 0;
    let minListVal = Infinity;
    // @ts-ignore
    lists.forEach((el, i) => { if (el.val < minListVal) { minListVal = el.val; minListIndice = i } });
    const node = new ListNode(minListVal);
    // @ts-ignore
    node.next = mergeKLists(lists.map((list, i) => i === minListIndice ? list.next : list))
    return node;
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

console.log(mergeKLists([l1, l2]));
