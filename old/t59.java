class Solution {
    public int[][] generateMatrix(int n) {
        int[][] a = new int[n][n];
        int sx = 0,sy = 0;
        int cnt = n/2;
        int now = 1;
        int x = 1;
        while(cnt>0){
            int i = sx,j = sy;
            for(;j<n-now;j++){
                a[i][j] = x++;
            }
            for(;i<n-now;i++){
                a[i][j] = x++;
            }
            for(;j>sy;j--){
                a[i][j] = x++;
            }
            for(;i>sx;i--){
                a[i][j] = x++;
            }
            sx++;
            sy++;
            now++;
            cnt--;
        }
        if(n%2!=0){
            a[n/2][n/2] = n*n;
        }
        return a;
    }
}
public class lc59{
    public static void main(String[] agrs){
        Solution sol = new Solution();
        int a[][] = sol.generateMatrix(6);
        for(int i = 0;i<a.length;i++){
            for(int j = 0;j<a[i].length;j++){
                System.out.printf("%d ",a[i][j]);
            }
            System.out.printf("\n");
        }
    }
}