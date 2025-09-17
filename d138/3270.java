class Solution {
    public int[] solve(int x){
        int a[] = new int[4];
        int now = 0;
        while(x>0){
            a[now] = x%10;
            x/=10;
            now++;
        }
        return a;
    }

    public int generateKey(int num1, int num2, int num3) {
        int[] a1 = solve(num1),a2 = solve(num2),a3 = solve(num3);
        int ans = 0;
        for(int i = 3;i>=0;i--){
            a1[i] = Math.min(a1[i],Math.min(a2[i],a3[i]));
            ans = ans*10+a1[i];
        }
        return ans;
    }
}