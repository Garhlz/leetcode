#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr) return {};
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        vector<vector<int>> ans;
        while (!q.empty()) {
            int num = q.size();  // 当前层的数量
            vector<int> curLevel;
            for (int i = 0; i < num; i++) {
                auto front = q.front();
                q.pop();
                curLevel.push_back(front->val);
                if (front->left != nullptr) q.push(front->left);
                if (front->right != nullptr) q.push(front->right);
            }
            if(level & 1){
                reverse(curLevel.begin(), curLevel.end());
            }
            level++;
            ans.push_back(curLevel);
        }
        return ans;
    }
};
