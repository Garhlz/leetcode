class Solution {
    private boolean prime(int x){
        for(int i = 2;i*i<=x;i++){
            if(x%i==0)return false;
        }
        return true;
    }

    public int nonSpecialCount(int l, int r) {
        int l1 = (int)Math.sqrt(l);
        int r1 = (int)Math.sqrt(r)+1;
        int ans = 0;
        for(int i = l1;i<=r1;i++){
            if(prime(i)){
                int t = i*i;
                if(t>=l && t<=r && t>1)ans++;
            }
        }
        return (r-l+1) - ans;
    }
}