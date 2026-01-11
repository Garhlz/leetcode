#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

struct cmp {
    bool operator()(ListNode* a, ListNode* b) { return a->val > b->val; }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> q;
        for (auto list : lists) {
            if (list != nullptr) q.push(list);
        }
        ListNode head(0);
        ListNode* now = &head;
        while (!q.empty()) {
            auto front = q.top();
            q.pop();
            if (front != nullptr) {
                now->next = front;
                now = now->next;
                if (front->next != nullptr) {
                    q.push(front->next);
                }
            }
        }
        return head.next;
    }
};
