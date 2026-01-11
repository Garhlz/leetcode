#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return;

        // 1. 使用快慢指针寻找链表中点
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // slow 指向中点。
        // 将链表分为两段：head ... slow 和 slow->next ... end
        ListNode* head2 = slow->next;
        slow->next = nullptr;  // 断开两段链表

        // 2. 反转后半段链表 (head2)
        head2 = reverseList(head2);

        // 3. 合并两个链表 (head 和 head2)
        mergeList(head, head2);
    }

    // 辅函数：反转链表
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }

    // 辅函数：交叉合并
    void mergeList(ListNode* l1, ListNode* l2) {
        while (l1 != nullptr && l2 != nullptr) {
            // 暂存两边的下一个节点
            ListNode* l1_next = l1->next;
            ListNode* l2_next = l2->next;

            // 连线：l1 -> l2
            l1->next = l2;
            // l2 指向 l1 原来的下一个
            l1 = l1_next;

            // 连线：l2 -> l1_next
            l2->next = l1;
            // l2 移动到下一个
            l2 = l2_next;
        }
    }
};
