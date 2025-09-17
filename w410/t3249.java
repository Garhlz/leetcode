import java.util.*;
class Solution {
    int ans = 0;
    public int countGoodNodes(int[][] edges) {
        int n = edges.length+1;
        List<Integer>[] a = new ArrayList[n]; //注意这里并没有new空间，只是声明了一个数组，并未赋值
        Arrays.setAll(a,i->new ArrayList<>());
        for(int i = 0;i<edges.length;i++){
            int x = edges[i][0];
            int y = edges[i][1];
            a[x].add(y);
            a[y].add(x);
        }
        dfs(0,-1,a);
        return ans;
    }
    private int dfs(int x,int f,List<Integer>[] a){
        List<Integer> now = new ArrayList<>();
        int ret = 0;
        int sz0 = 0;
        int flag = 1;
        for(int y:a[x]){
            if(y==f)continue;
            int d = dfs(y,x,a);
            if(ret==0){
                sz0 = d;
            }
            else if(sz0!=d){
                flag = 0;
            }
            ret+=d;
        }
        ans+=flag;
        ret++;
        return ret;
    }
}