/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    int ans = 1;
    public int dfs(TreeNode now){
        if(now==null)return 0;//当前子树结点个数
        //路径长度就是结点个数-1
        //实际上是使每个结点作为两个最深点的lca，回溯求最大值，而不是直接遍历两个点
        int l = dfs(now.left);
        int r = dfs(now.right);
        ans = Math.max(ans,l+r+1);
        return Math.max(l,r)+1;
    }
    public int diameterOfBinaryTree(TreeNode root) {
        dfs(root);
        return ans;
    }
}