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

function mergeKLists(lists: Array<ListNode | null>): ListNode | null {
  // all is null
  if (lists.filter((list) => list === null).length === lists.length) {
    return null;
  }

  const heap: ListNode[] = [];

  // initialize heap with the first node of each list
  lists.forEach((list) => {
    if (list !== null) {
      heap.push(list);
    }
  });

  // create dummy head for result list
  const dummyHead = new ListNode(0);//tmp
  let tail = dummyHead;

  while (heap.length > 0) {
    // find minimum node in heap
    let minNode = heap[0];
    let minIndex = 0;

    for (let i = 1; i < heap.length; i++) {
      if (heap[i].val < minNode.val) {
        minNode = heap[i];
        minIndex = i;
      }
    }

    // remove minimum node from heap
    heap.splice(minIndex, 1);

    // add minimum node to result list
    tail.next = minNode;
    tail = tail.next;

    // add next node from the same list to heap
    if (minNode.next !== null) {
      heap.push(minNode.next);
    }
  }
  // skip the dummyHead (because it was tmp)
  return dummyHead.next;
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
console.log(mergeKLists([l1, l2]));
