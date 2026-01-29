#include <bits/stdc++.h>
using namespace std;
struct pair_hash {
  inline size_t operator()(const pair<int, int> &v) const {
    // 一个简单的组合算法：让第一个值左移并异或第二个值
    // 实际开发中常用类似于 Boost 的 hash_combine 算法
    return hash<int>()(v.first) ^
           (hash<int>()(v.second) + 0x9e3779b9 + (hash<int>()(v.first) << 6) +
            (hash<int>()(v.first) >> 2));
  }
};

struct cmp {
  bool operator()(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first)
      return a.second < b.second;
    else
      return a.first < b.first;
  }
};

class AuctionSystem {
public:
  AuctionSystem();

  void addBid(int userId, int itemId, int bidAmount);

  void updateBid(int userId, int itemId, int newAmount);

  void removeBid(int userId, int itemId);

  int getHighestBidder(int itemId);

private:
  unordered_map<int,
                priority_queue<pair<int, int>, vector<pair<int, int>>, cmp>>
      pqs;
  // 存储每个物品对应的懒删除堆
  unordered_map<pair<int, int>, int, pair_hash> mp;
  // 存储每个人，物品对应的价格
};

/**
 * Your AuctionSystem object will be instantiated and called as such:
 * AuctionSystem* obj = new AuctionSystem();
 * obj->addBid(userId,itemId,bidAmount);
 * obj->updateBid(userId,itemId,newAmount);
 * obj->removeBid(userId,itemId);
 * int param_4 = obj->getHighestBidder(itemId);
 */
AuctionSystem::AuctionSystem() {}

void AuctionSystem::addBid(int userId, int itemId, int count) {
  pqs[itemId].push({count, userId});
  mp[{userId, itemId}] = count;
}

void AuctionSystem::updateBid(int userId, int itemId, int count) {
  addBid(userId, itemId, count);
}

void AuctionSystem::removeBid(int userId, int itemId) {
  if (mp.find({userId, itemId}) != mp.end()) {
    mp.erase({userId, itemId});
  }
}

int AuctionSystem::getHighestBidder(int itemId) {
  auto &pq = pqs[itemId];
  while (!pq.empty()) {
    auto [count, userId] = pq.top();
    if (mp.find({userId, itemId}) == mp.end() ||
        mp[{userId, itemId}] != count) {
      pq.pop();
    } else {
      return userId;
    }
  }
  return -1;
}
