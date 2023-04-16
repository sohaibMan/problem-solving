// Definition for singly - linked list.
var ListNode = /** @class */ (function () {
    function ListNode(val, next) {
        this.val = (val === undefined ? 0 : val);
        this.next = (next === undefined ? null : next);
    }
    return ListNode;
}());
function addTwoNumbers(l1, l2) {
    // on consider que l1 et l2 sont de meme taille 
    if (l1 === null || l2 === null)
        return null;
    var curry = l1.val + l1.val >= 10 ? 1 : 0;
    var l = new ListNode(l1.val + l2.val + curry === 0 ? 0 : -10);
    l1.next = addTwoNumbers(l1.next, l2.next);
    return l;
}
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
console.log(addTwoNumbers(l1, l2));
