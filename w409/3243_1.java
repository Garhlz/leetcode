import java.util.*;

class Solution {
    public int[] shortestDistanceAfterQueries(int n, int[][] queries) {
        List<Integer>[] g = new ArrayList[n-1];
        Arrays.setAll(g,i->new ArrayList<>());
        for(int i = 0;i<n-1;i++){
            g[i].add(i+1);
        }
        int[] ans = new int[queries.length];
        int[] vis = new int[n-1];
        for(int i = 0;i<queries.length;i++){
            g[queries[i][0]].add(queries[i][1]);
            ans[i] = bfs(i+1, g, vis, n);
        }
        return ans;
    }

    public int bfs(int i, List<Integer>[] g, int[] vis, int n){
        Queue<Integer> q= new LinkedList<>();
        q.add(0);
        int[] lev = new int[n];
        while(!q.isEmpty()){
            int u = q.poll();
            for(int v:g[u]){
                if(v==n-1)return lev[n-1] = lev[u]+1;
                if(vis[i]!=i){
                    vis[v] = i;
                    lev[v] = lev[u]+1;
                    q.add(v);
                }
            }
        }
        return lev[n-1];
    }
}
