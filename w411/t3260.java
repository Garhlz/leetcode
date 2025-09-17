import java.util.*;

class Solution {
    public String largestPalindrome(int n, int k) {
        int[] pow = new int[n];
        pow[0] = 1;
        for(int i = 1;i<n;i++){
            pow[i] = pow[i-1] * 10 % k;
            //位数的基数甚至都可以一直取模
        }
        char[] ans = new char[n];
        int m = (n+1)/2;
        boolean[][] vis = new boolean[m+1][k];
        //j表示取模之后的数值
        dfs(0,0,n,k,m,pow,ans,vis);
        return new String(ans);
    }

    //要么全部变成对象内全局，要么全部传入
    private boolean dfs(int i, int j, int n, int k, int m, int[] pow, char[] ans, boolean[][] vis){
        if(i==m)return j == 0;
        //全部填完之后，发现不可，开始回溯
        //不会走回头路，而且是回溯的时候赋值
        //修改的是字符数组，最后直接转换成string即可
        vis[i][j] = true;
        //第一维：位置 第二维：数字
        for(int p = 9;p>=0;p--){
            int q;
            if(n%2!=0 && i==m-1){
                q = (j + p * pow[i]) % k;
            }else{
                q = (j + p * (pow[i] + pow[n-1-i])) % k;
            }
            if(!vis[i+1][q] && dfs(i+1, q, n, k, m, pow, ans, vis)){
                ans[i] = ans[n-1-i] = (char)(p+'0');
                return true;
            }
        }
        return false;
    }
}
public class t3260{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        Solution solution = new Solution();
        String s = solution.largestPalindrome(n, k);
        System.out.println(s);
    }
}