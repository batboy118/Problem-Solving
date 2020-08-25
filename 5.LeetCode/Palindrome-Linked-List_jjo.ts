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

function isPalindrome(head: ListNode | null): boolean {
  let len = 0;
  let temp = head;

  //길이 구함
  while(temp){
      temp = temp.next;
      len++;
  }
  let half = Math.floor(len/2);
  let second = head;

  //중간까지 이동
  for(let i = 0 ; i < half && second; i++){
      second = second.next;
  }

  //리스트 절반 뒤집기
  let rev = null;
  while(second){
      temp = new ListNode();
      temp.val = second.val;
      temp.next = rev;
      rev = temp;
      second = second.next;
  }

  //check palindrome
  while(half--){
      if(rev && head){
          if(rev.val != head.val) return false;
          rev = rev.next;
          head = head.next;
      }
  }
  return true;
};
