#include <bits/stdc++.h>

#include <climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
// 对于每个结点，返回给父节点的贡献是node->val + max(leftMax + rightMax)
// 对于每个结点，更新经过这个结点的最大值
class Solution {
private:
    int maxsum = INT_MIN;

public:
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return maxsum;
    }

    int dfs(TreeNode* root) {
        if (root == nullptr) return 0;
        int leftMax = max(dfs(root->left), 0);
        int rightMax = max(dfs(root->right), 0);

        maxsum = max(maxsum, leftMax + rightMax + root->val);

        return root->val + max(leftMax, rightMax);
    }
};
