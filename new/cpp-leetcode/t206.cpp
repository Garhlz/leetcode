
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if (head == nullptr)
            return nullptr;
        auto now = head;
        auto nxt = now->next;
        now->next = nullptr;
        while (nxt != nullptr)
        {
            auto nxt1 = nxt->next;
            nxt->next = now;
            now = nxt;
            nxt = nxt1;
        }
        return now;
    }
};