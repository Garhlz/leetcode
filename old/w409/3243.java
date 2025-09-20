import java.util.*;

class Solution {
    public int q;
    public int[] shortestDistanceAfterQueries(int n, int[][] queries) {
        q = queries.length;
        List<Integer>[] g = new ArrayList[n-1];
        Arrays.setAll(g,i->new ArrayList<>());
        //lamda表达式，意思就是给数组的每一个ArrayList元素new一块空间
        for(int i = 0;i<n-1;i++)g[i].add(i+1);//就是建立邻接表
        int[] ans = new int[q];
        int[] vis = new int[n-1];
        for(int i = 0;i<q;i++){
            g[queries[i][0]].add(queries[i][1]);
            ans[i] = bfs(i + 1, g, vis, n);
        }
        return ans;
    }

    public int bfs(int i, List<Integer>[] g, int[] vis, int n){
        Queue<Integer> q = new LinkedList<>();
        q.add(0);
        //又需要记录层数
        //题解分层是通过每层建立一个新数组完成的，而不是直接队列
        int[] lev = new int[n];
        while(!q.isEmpty()){
            int u = q.poll();
            for(int v:g[u]){
                if(v==n-1)return lev[n-1] = lev[u]+1;
                if(vis[v]!=i){//这一轮循环没有入队过
                    vis[v] = i;
                    lev[v] = lev[u]+1;
                    q.add(v);
                }
            }
        }
        return lev[n-1];
    }
}
