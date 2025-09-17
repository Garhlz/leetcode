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
    int num = 0;
    int k;
    int ans = -1;
    public int kthSmallest(TreeNode root, int k) {
        this.k = k;
        chk(root);
        return ans;
    }

    public void chk(TreeNode root){
        if(num==k)return;
        if(root.left!=null)chk(root.left);
        num++;
        if(num==k)ans = root.val;
        if(root.right!=null)chk(root.right);
    }
}