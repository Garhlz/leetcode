class Solution {
    public long maxEnergyBoost(int[] a, int[] b) {
        int n = a.length;
        long[][] dp = new long[n][2];
        dp[0][0] = a[0];dp[0][1]  = b[0];
        dp[1][0] = dp[0][0]+a[1];dp[1][1] = dp[0][1]+b[1];
        for(int i = 2;i<n;i++){
            dp[i][0] = Math.max(dp[i-1][0]+a[i],dp[i-2][1]+a[0]);
            dp[i][1] = Math.max(dp[i-1][1]+b[i],dp[i-2][0]+b[0]);
        }
        return Math.max(dp[n-1][0],dp[n-1][1]);
    }
}