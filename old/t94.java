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


import java.util.*;
class Solution {
    void dfs(TreeNode now){
        if(now==null)return;
        if(now.left!=null)dfs(now.left);
        a.add(now.val);
        if(now.right!=null)dfs(now.right);
    }
    ArrayList<Integer> a = new ArrayList<Integer>();

    public List<Integer> inorderTraversal(TreeNode root) {
        dfs(root);
        return a;
    }
}