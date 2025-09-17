class Solution {
    public int minFlips(int[][] grid) {
        int n = grid.length,m = grid[0].length;
        int ans = 0;
        for(int i = 0;i<n/2;i++){
            for(int j = 0;j<m/2;j++){
                int t1 = 0;
                if(grid[i][j]==0)t1++;
                if(grid[i][m-j-1]==0)t1++;
                if(grid[n-i-1][j]==0)t1++;
                if(grid[n-i-1][m-j-1]==0)t1++;
                ans+=Math.min(t1,4-t1);
            }
        }
        if(n%2==1&&m%2==1){
            if(grid[n/2][m/2]==1)ans++;
        }
        int t1 = 0,t2 = 0;
        if(n%2==1){
            for(int i = 0;i<m/2;i++){
                if(grid[n/2][i]!=grid[n/2][m-i-1])t1++;
                if(grid[n/2][i]==1&&grid[n/2][m-i-1]==1)t2+=2;
            }
        }
        if(m%2==1){
            for(int i = 0;i<n/2;i++){
                if(grid[i][m/2]!=grid[n-i-1][m/2])t1++;
                if(grid[i][m/2]==1&&grid[n-i-1][m/2]==1)t2+=2;
            }
        }
        if(t1>0)ans+=t1;
        else ans+=(t2%4);
        return ans;
    }
}