import java.util.*;
class Solution {
    public int maxScore(List<List<Integer>> grid){
        Map<Integer,Integer> pos = new HashMap<>();
        int m = grid.size();
        for(int i = 0;i<m;i++){
            for(int x : grid.get(i)){
                pos.merge(x, 1<<i , (a,b)->a|b);
            }
        }
    }
    List<Integer> nums = new ArrayList<>(pos.keySet());
    int n = nums.size();
    int memo[][] = new int[n][1<<m];
    for(int row[] : memo){
        Arrays.fill(row,-1);
    }
    return dfs(n-1, 0, pos, nums, memo);

    private int dfs(int i,int j, Map<Integer, Integer> pos, List<Integer> nums, int[][] memo){
        if(i<0){
            return 0;
        }
        if(memo[i][j]!=-1){
            return memo[i][j];
        }
        int res = dfs(i-1, j, pos, nums, memo);
        int x = nums.get(i);
        for(int t = pos.get(x),lb;t>0;t^=lb){
            lb = t & -t;
            if ((j & lb) == 0) { // 没选过第 k 行的数
                res = Math.max(res, dfs(i - 1, j | lb, pos, nums, memo) + x);
            }
        }
        return memo[i][j] = res;
    }
}

