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
    public int[] a;

    public TreeNode sortedArrayToBST(int[] nums) {
        a = nums;//最好就是不直接转化
        return search(0,a.length - 1);
    }

    public TreeNode search(int l,int r){
        int m = (l+r)/2;
        TreeNode root = new TreeNode(a[m]);//不可以直接通过[]访问
        if(l<=m-1)root.left = search(l,m-1);
        if(m+1<=r)root.right = search(m+1,r);
        return root;
    }

}