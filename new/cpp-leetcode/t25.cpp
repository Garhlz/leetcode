#include <bits/stdc++.h>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
private:
  auto len(ListNode *node) -> int {
    auto cur = node;
    int res = 0;
    while (cur != nullptr) {
      cur = cur->next;
      res++;
    }
    return res;
  }

public:
  ListNode *reverseKGroup(ListNode *head, int k) {
    auto originHead = head;
    int length = len(head);
    int times = length / k;

    ListNode *lastTail = nullptr;
    ListNode *next = head->next;
    ListNode *now = head;
    while (times--) {
      for (int i = 0; i < k - 1; i++) {
        auto tmp = now->next;
        next->next = now;
        now = next;
        next = tmp;
      }
      head->next = lastTail;
      lastTail = head;
    }
  }
};
