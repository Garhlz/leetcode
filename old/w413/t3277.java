class Solution {
    public int[] maximumSubarrayXor(int[] nums, int[][] queries) {
        int n = nums.length;
        int dp[][] = new int[n][n];
        int mx[][] = new int[n][n];
        //从后往前，长度从小到大，转移计算当前区间最大值
        for(int i = n-1;i>=0;i--){
            dp[i][i] = nums[i];
            mx[i][i] = nums[i];
            for(int j = i+1;j<n;j++){
                dp[i][j] = dp[i+1][j] ^ dp[i][j-1];
                mx[i][j] = Math.max(dp[i][j],Math.max(mx[i+1][j],mx[i][j-1]));
            }
        }
        int t1 = queries.length;
        int ans[] = new int[t1];
        for(int i = 0;i<t1;i++){
            ans[i] = mx[queries[i][0]][queries[i][1]];
        }
        return ans;
    }
}

