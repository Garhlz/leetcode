class Solution{
    List<List<Integer>> a= new ArrayList<>();
    public List<List<Integer>> levelOrder(TreeNode root){
        dfs(root,0);
        return a;
    }
    public void dfs(TreeNode now,int d){
        if(now==null)return;
        if(a.size()==d){//当前层数比数列数量多
            List<Integer> t = new ArrayList<>();
            a.add(t);//动态加入新的一层
        }
        List<Integer> t = a.get(d);//当前这层，随机访问
        t.add(now.val);
        dfs(now.left,d+1);
        dfs(now.right,d+1);

    }
}