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
class Solution {//需要判断诸多边界条件，是否为null
    public ListNode swapPairs(ListNode head) {
        ListNode pred = null,x1 = head,x2,nxt;
        if(head!=null&&head.next!=null)head = head.next;
        while(x1!=null&&x1.next!=null){
            x2 = x1.next;
            nxt = x2.next;
            if(pred!=null)pred.next = x2;
            x2.next = x1;
            x1.next = nxt;
            if(nxt==null)break;
            pred = x1;
            x1 = nxt;
            if(x1.next==null)break;
            x2 = x1.next;
        }
        return head;
    }
}