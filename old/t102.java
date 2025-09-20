import java.util.*;

class Solution{
    public List<List<Integer>> a = new ArrayList<List<Integer>>();
    
    public List<List<Integer>> levelOrder(TreeNode root){
        if(root==null)return a;

        Queue<TreeNode> q = new LinkedList<TreeNode>();
        while(!q.isEmpty()){
            List<Integer> level = new ArrayList<Integer>();
            int n = q.size();
            for(int i = 0;i<n;i++){
                TreeNode now = q.poll();
                level.add(now.val);
                if(now.left!=null)q.add(now.left);
                if(now.right!=null)q.add(now.right);

            }
            a.add(level);
        }
        return a;
    }
}