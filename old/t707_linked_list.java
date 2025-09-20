class ListNode{
    int val;
    ListNode next;
    ListNode(){}
    ListNode(int val){
        this.val = val;
    }
}

class MyLinkedList {
    int size;
    ListNode head;

    public MyLinkedList() {
        size = 0;
        head = new ListNode(0);    
    }
    
    public int get(int index) {
        if(index<0||index>=size)return -1;
        ListNode now = head;
        for(int i = 1;i<=index+1;i++){//包含一个虚拟头节点head
            now = now.next;
        }
        return now.val;
    }
    
    public void addAtHead(int val) {
        addAtIndex(0, val);
    }
    
    public void addAtTail(int val) {
        addAtIndex(size, val);
    }
    //在index之前插入一个新的结点,pred是index结点的前驱，不能直接获得，需要从0开始遍历
    public void addAtIndex(int index, int val) {
        if(index>size)return;
        if(index<0)index = 0;
        size++;
        ListNode pred = head;
        for(int i = 0;i<index;i++)pred = pred.next;
        ListNode x = new ListNode(val);
        x.next = pred.next;
        pred.next = x;
    }
    
    public void deleteAtIndex(int index) {
        if(index<0||index>=size)return;
        size--;
        if(index==0)head = head.next;
        else{
            ListNode pred = head;
            for(int i = 0;i<index;i++)pred = pred.next;
            pred.next = pred.next.next;
        }
    }
}

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */