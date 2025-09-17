import java.util.*;
class Solution {
    public long countGoodIntegers(int n, int k) {
        int[] fac = new int[n+1];
        fac[0] = 1;
        for(int i = 1;i<=n;i++){
            fac[i] = fac[i-1] * i;
        }
        long ans = 0;
        Set<String> vis = new HashSet<>();
        int base = (int)Math.pow(10, (n-1)/2);
        //直接暴力算出可以取得回文数范围，然后枚举
        for(int i = base;i<base*10;i++){
            String s = Integer.toString(i);
            s+= new StringBuilder(s).reverse().substring(n%2);
            //非常暴力，枚举一半然后直接翻转加上去，再转成Long
            if(Long.parseLong(s) % k > 0){
                continue;
            }
            char[] s1 = s.toCharArray();
            Arrays.sort(s1);
            if(!vis.add(new String(s1))){
                continue;
            }
            int[] cnt = new int[10];
            for(char c:s1){
                cnt[c-'0']++;
            }
            int res = (n - cnt[0]) * fac[n-1];
            for(int c:cnt){
                res/=fac[c];
            }
            ans+=res;
        }
        return ans;
    }
}