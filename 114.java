import java.util.TreeMap;

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
    public void flatten(TreeNode root) {
        root = dfs(root);
    }

    public TreeNode dfs(TreeNode node){
        if(node==null)return null;
        TreeNode l = node.left,r = node.right;
        if(l!=null){
            node.right = l;
            node.left = null;
            node = dfs(l);//左序的最后一个,定是叶子结点
        }
        
        if(r!=null){
            node.right = r;
            node = dfs(r);//返回最后一个
        }
        return node;
    }
}