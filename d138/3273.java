import java.util.*;

class Solution {
    public long minDamage(int power, int[] damage, int[] health) {
        int n = health.length;
        int[][] a = new int[n][2];
        for(int i = 0;i<n;i++){
            a[i][0] = (health[i] - 1) / power + 1;//杀死需要的天数
            a[i][1] = damage[i];
        }
        Arrays.sort(a,(p,q) -> p[0]*q[1] - q[0] * p[1]);
        //lambda表达式，相当于继承comparator接口，p/q较小的放在前面

        long ans = 0;
        long s = 0;
        for(int[] p : a){
            s+=p[0];
            ans+=s * p[1];
        }
        return ans;
    }
}