class Solution {
    public int countKConstraintSubstrings(String s, int k) {
        int t1 = 0,t2 = 0;
        int p = 0,q = 0;
        int n = s.length();
        int ans = 0;
        while(p<n && q<n){
            if(s.charAt(p)=='1')t1++;
            else t2++;
            while(t1>k && t2>k){
                if(s.charAt(q)=='1')t1--;
                else t2--;
                q++;
            }
            ans+=(p-q+1);
            p++;
        }
        return ans;
    }
}