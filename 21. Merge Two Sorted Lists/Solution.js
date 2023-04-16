//  Definition for singly - linked list.
var ListNode = /** @class */ (function () {
    function ListNode(val, next) {
        this.val = (val === undefined ? 0 : val);
        this.next = (next === undefined ? null : next);
    }
    return ListNode;
}());
function mergeTwoLists(list1, list2) {
    if (list1 === null && list2 === null)
        return null;
    if (list1 === null && list2 !== null) {
        return list2;
    }
    if (list2 === null && list1 !== null) {
        return list1;
    }
    var newNode = new ListNode();
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
}
;
var l1 = new ListNode(2);
var node1 = new ListNode(4);
l1.next = node1;
var node2 = new ListNode(3);
node1.next = node2;
node2.next = null;
var l2 = new ListNode(5);
var node3 = new ListNode(6);
l2.next = node3;
var node4 = new ListNode(4);
node3.next = node4;
node4.next = null;
console.log(mergeTwoLists(l1, l2));
