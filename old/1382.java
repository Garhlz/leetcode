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
    List<Integer> a = new ArrayList<>();
    public TreeNode balanceBST(TreeNode root) {
        getList(root);
        return build(0,a.size() - 1);
    }
    public void getList(TreeNode root){//递归中序遍历，生成数列
        if(root.left!=null)getList(root.left);
        a.add(root.val);
        if(root.right!=null)getList(root.right);
    }

    public TreeNode build(int l,int r){
        int m = (l+r)/2;
        TreeNode root = new TreeNode(a.get(m));//以中序遍历的中间点作为根
        if(l<=m-1)root.left = build(l,m-1);
        if(r>=m+1)root.right = build(m+1,r);
        return root;
    }
}