import java.util.*;
class Solution{
    public int[] timeTaken(int[][] edges){
        List<Integer>[] g = new ArrayList[edges.length+1];
        Arrays.setAll(g,i -> new ArrayList<>());
        for(int i = 0;i<edges.length;i++){
            int x = edges[i][0];
            int y = edges[i][1];
            g[x].add(y);
            g[y].add(x);
        }

        int[][] nodes = new int[g.length][3];
        dfs(0,-1,g,nodes);
        int[] ans = new int[g.length];
        reroot(0,-1,0,g,nodes,ans);
        return ans;
    }

    private int dfs(int x,int f,List<Integer>[] g, int[][] nodes){
        int m1 = 0,m2 = 0,ms = 0;
        for(int y : g[x]){
            if(y==f)continue;
            int dep = dfs(y,x,g,nodes) + 2 - (y % 2);
            if(dep>m1){
                m2 = m1;
                m1 = dep;
                ms = y;//深度最大儿子的编号
            }
            else if(dep>m2){
                m2 = dep;
            }
        }
        nodes[x][0] = m1;
        nodes[x][1] = m2;
        nodes[x][2] = ms;
        return m1;
    }


    private void reroot(int x,int f,int up,List<Integer>[] g,int[][] nodes,int[] ans){
        int m1 = nodes[x][0];
        int m2 = nodes[x][1];
        int ms = nodes[x][2];
        ans[x] = Math.max(up,m1);
        for(int y : g[x]){
            if(y==f)continue;
            int t;
            if(y==ms)t = m2;
            else t = m1;
            t = t+2-(x%2);
            reroot(y,x,Math.max(up,t),g,nodes,ans);
        }
    }
}