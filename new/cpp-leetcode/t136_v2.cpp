#include <list>
#include <unordered_map>
#include <utility> // for std::pair

class LRUCache
{
private:
    int cap;

    // 双向链表：存 <Key, Value>
    // 头部 (begin) 是最近使用 (MRU)，尾部 (back) 是最久未用 (LRU)
    std::list<std::pair<int, int>> l;

    // 哈希表：存 Key -> 链表节点的迭代器
    // 这样我们就能 O(1) 找到链表里的那个节点
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> mp;

public:
    LRUCache(int capacity) : cap(capacity) {}

    int get(int key)
    {
        // 1. 查表
        auto it = mp.find(key);
        if (it == mp.end())
            return -1;

        // 2. 找到了：不仅要返回 Value，还要把这个节点移到链表头部
        // list_it 是存放在 map value 里的链表迭代器
        auto list_it = it->second;

        // 【神技 splice】：把 list_it 指向的节点，剪切并移动到 l.begin() 前面
        // 这一步是 O(1)，且 list_it 迭代器本身不会失效，所以不需要更新 map！
        l.splice(l.begin(), l, list_it);

        // 3. 返回 Value (链表节点里的 second)
        return list_it->second;
    }

    void put(int key, int value)
    {
        auto it = mp.find(key);

        // === 情况 A: Key 已存在 ===
        if (it != mp.end())
        {
            auto list_it = it->second;
            // 更新 Value
            list_it->second = value;
            // 移到头部 (标记为最近使用)
            l.splice(l.begin(), l, list_it);
            return;
        }

        // === 情况 B: Key 不存在 ===
        if (mp.size() == cap)
        {
            // 容量满了，淘汰链表尾部 (LRU)
            // 注意：要先删 map 里的记录，因为 pop_back() 后迭代器就失效了，再找 key 就麻烦了
            int key_to_del = l.back().first;
            mp.erase(key_to_del);
            l.pop_back();
        }

        // 插入新节点到头部
        l.emplace_front(key, value);
        // 记下新节点的迭代器到 map 中
        mp[key] = l.begin();
    }
};