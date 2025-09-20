/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode r = dummy,l = dummy;
        for(int i = 0;i<n+1;i++){
            r = r.next;
            if(r==null)break;
        }
        while(r.next!=null){
            r = r.next;
            l = l.next;
        }
        l.next = l.next.next;
        return dummy.next;
    }
}