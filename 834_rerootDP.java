class Solution {
    private List<Integer>[] g;
    private int[] ans,siz;
    public int[] sumOfDistancesInTree(int n, int[][] edges) {
        g = new ArrayList[n];//此时先不确定泛型
        Arrays.setAll(g,i->new ArrayList<>());
        for(var x:edges){
            int a = x[0],b = x[1];
            g[a].add(b);
            g[b].add(a);
        }//邻接表，建图
        ans = new int[n];
        siz = new int[n];
        dfs(0,-1,0);
        reroot(0,-1);
        return ans;
    }

    private void dfs(int x,int fa,int dep){
        ans[0]+=dep;
        siz[x] = 1;
        for(int y : g[x]){
            if(y==fa)continue;
            dfs(y,x,dep+1);
            siz[x]+=siz[y];//子树节点数量，包括自己
        }
    }

    private void reroot(int x,int fa){
        for(int y:g[x]){
            if(y!=fa){
                ans[y] = ans[x] + g.length - 2*siz[y];
                reroot(y,x);
            }
        }
    }
}