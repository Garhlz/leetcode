#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> ans;
    if (root == nullptr) {
      return ans;
    }
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
      int curNumber = q.size();
      vector<int> curArray;
      while (curNumber--) {
        auto front = q.front();
        q.pop();
        curArray.push_back(front->val);
        if (front->left != nullptr)
          q.push(front->left);
        if (front->right != nullptr)
          q.push(front->right);
      }
      ans.push_back(curArray);
    }
    return ans;
  }
};
