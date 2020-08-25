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

function mergeTwoLists(l1: ListNode | null, l2: ListNode | null): ListNode | null {
    let new_list = new ListNode();
    let now = new_list;
    while(l1 && l2){
        let temp = new ListNode();
        if(l1.val > l2.val){
            temp.val = l2.val;
            l2 = l2.next;
        } else{
            temp.val = l1.val;
            l1 = l1.next;
        }
        now.next = temp;
        now = temp;
    }
    if(l1){
        now.next = l1;
    } else{
        now.next = l2;
    }
    return new_list.next;
};
