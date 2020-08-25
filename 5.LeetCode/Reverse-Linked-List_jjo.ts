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

function reverseList(head: ListNode | null): ListNode | null {
  let rev = null;
  while(head){
      let temp = new ListNode();
      temp.val = head.val;
      temp.next = rev;
      rev = temp;
      head = head.next;
  }
  return rev;
};
