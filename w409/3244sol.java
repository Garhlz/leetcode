class UnionFind{
    public final int[] fa;
    public UnionFind(int size){
        fa = new int[size];
        for(int i = 1;i<size;i++)fa[i] = i;
    }

    public int find(int x){
        if(x==fa[x])return x;
        else return fa[x] = find(fa[x]);
    }
}

class Solution{
    public int[] shortestDistanceAfterQueries(int n,int[][] q){
        UnionFind uf = new UnionFind(n-1);
        int[] ans = new int[q.length];
        int cnt = n-1;
        for(int qi = 0;qi<q.length;qi++){
            int l = q[qi][0],r = q[qi][1] - 1;
            int fa = uf.find(r);
            for(int i = uf.find(l);i<r;i = uf.find(i+1)){
                uf.fa[i] = fa;
                cnt--;
            }
            ans[qi] = cnt;
        }
        return ans;
    }
}