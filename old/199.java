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
    List<Integer> list;
    public List<Integer> rightSideView(TreeNode root) {
        list = new ArrayList<>();//注意大写
        dfs(root,1);
        return list;
    }
    public void dfs(TreeNode root,int dep){
        if(root==null)return;//注意边界
        if(list.size()<dep)list.add(root.val);//第一个遍历到当前这层的才加入
        if(root.right!=null)dfs(root.right,dep+1);
        if(root.left!=null)dfs(root.left,dep+1);
    }
}