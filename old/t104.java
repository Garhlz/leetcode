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
    public int dep = 0;

    void dfs(TreeNode now,int d){
        if(now==null)return;
        dep = Math.max(dep,d);
        dfs(now.left,d+1);
        dfs(now.right,d+1);
        //进入之后再判断是否为null
    }

    public int maxDepth(TreeNode root) {
        dfs(root,1);
        return dep;
    }
}