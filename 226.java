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
    public void dfs(TreeNode now){
        if(now==null)return;
        dfs(now.left);
        dfs(now.right);
        TreeNode tmp = now.left;
        now.left = now.right;
        now.right = tmp;
    }

    public TreeNode invertTree(TreeNode root) {
        //在回溯的时候修改即可
        dfs(root);
        return root;
    }
}