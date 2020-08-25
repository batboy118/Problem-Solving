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
  let one = head;
  let two = head;
  let len = 0;
  while(one){
      len++;
      one = one.next;
  }
  let cnt = len - n;
  if(head && cnt == 0) return head.next
  while(two && --cnt){
      two = two.next;
  }
  if(two && two.next == null) two.next = null;
  else if(two && two.next) two.next = two.next.next;
  console.log(head)
  return head
};
