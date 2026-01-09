#include <deque>
#include <unordered_map>
#include <vector>

class LRUCache
{
private:
    // 这里的 pair: <timestamp, key>
    std::deque<std::pair<int, int>> arr;

    // 这里的 pair: <timestamp, value>
    struct Node
    {
        int time;
        int value;
    }; // 这里保留 struct 读起来清晰点，或者也用 pair
    std::unordered_map<int, Node> mp;

    int cap;
    int global_time; // 这里的 cnt 其实就是 mp.size()，不需要单独维护

    // 核心复用函数：清理头部的过期数据
    // 返回值：如果头部是有效数据，返回 true；如果队列空了，返回 false
    bool clean_stale_data()
    {
        while (!arr.empty())
        {
            auto [t, key] = arr.front();

            // 情况1: Key 已经不在 map 里了 (物理删除)
            if (mp.find(key) == mp.end())
            {
                arr.pop_front();
                continue;
            }

            // 情况2: Key 还在，但时间戳对不上 (逻辑过时)
            if (mp[key].time != t)
            {
                arr.pop_front();
                continue;
            }

            // 头部是有效数据，停止清理
            return true;
        }
        return false;
    }

public:
    LRUCache(int capacity) : cap(capacity), global_time(0)
    {
        arr.clear();
        mp.clear();
    }

    int get(int key)
    {
        if (mp.find(key) == mp.end())
            return -1;

        global_time++;
        // 更新 map 中的时间戳
        mp[key].time = global_time;
        // 懒更新：只管往后加，不管前面
        arr.emplace_back(global_time, key);

        return mp[key].value;
    }

    void put(int key, int value)
    {
        global_time++;
        arr.emplace_back(global_time, key);
        mp[key] = {global_time, value};

        // 1. 触发式 GC (防止 arr 无限膨胀)
        // 只有当 arr 长度严重超过 cap 时才整理，分摊 O(1)
        if (arr.size() > cap * 2)
        {
            clean_stale_data();
        }

        // 2. 容量检查 (标准的 LRU 淘汰)
        // 注意：这里要用 mp.size() 来判断实际元素个数
        while (mp.size() > cap)
        {
            // 确保头部是有效元素 (因为可能前面的都是垃圾)
            if (clean_stale_data())
            {
                // 找到了真正的 victim (最老且有效的)
                auto [t, k] = arr.front();
                arr.pop_front();
                mp.erase(k); // 真正的删除
            }
            else
            {
                // 理论上不可能进这里，除非 mp.size() > cap 但 arr 全是空的
                break;
            }
        }
    }
};