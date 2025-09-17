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
/*
 * 可以借鉴递归的思路，参数里放置上下界，同时满足即可
 * 注意是严格单调的
 */
class Solution {
    boolean flag = true;
    public boolean isValidBST(TreeNode root) {
        chk(root,Long.MIN_VALUE,Long.MAX_VALUE);
        return flag;
    }

    public void chk(TreeNode root,long l,long r){
        if(root.val<=l||root.val>=r)flag = false;
        if(!flag)return;
        if(root.left!=null)chk(root.left,l,root.val);
        if(root.right!=null)chk(root.right,root.val,r);
    }
}