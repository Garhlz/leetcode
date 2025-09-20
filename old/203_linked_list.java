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

class ListNode{
    public int val;
    public ListNode next;
    ListNode(){}
    ListNode(int val){
        this.val = val;
    }
    ListNode(int val,ListNode next){
        this.val = val;
        this.next = next;
    }
}
class Solution {
    public ListNode removeElements(ListNode head, int val) {
        while(head.val==val){
            head = head.next;
        }
        ListNode now = head;
        while(now!=null){
            while(now.next!=null&&now.nxt.val==val){
                now.next = now.next.next;
            }
            now = now.next;
        }
        return head;
    }
}