import java.util.*;
class Solution{
    public int kthSmallest(TreeNode root,int k){
        Bst bst = new Bst(root);
        return bst.kthSmallest(k);
    }
}

class Bst{
    TreeNode root;
    Map<TreeNode, Integer> num;
    public Bst(TreeNode root){//组合一个类
        this.root = root;
        this.num = new HashMap<TreeNode,Integer>();
        build(root);
    }

    private int build(TreeNode node){
        if(node==null)return 0;
        num.put(node, 1 + build(node.left) + build(node.right));
        return num.get(node);
    }

    public int kthSmallest(int k){
        TreeNode node = this.root;
        while(node!=null){//直接二分搜索，写成递推
            int l = num.getOrDefault(node,0);//后者是缺省值，因为get会返回0
            if(l < k-1){
                node = node.right;
                k -= l+1;//注意要减掉，因为是递归的
            }
            else if(l==k-1)break;
            else{
                node = node.left;
            }
        }
        return node.val;

    }
}