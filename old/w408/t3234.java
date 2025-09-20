class Solution {
    public int numberOfSubstrings(String s) {
        int n = s.length();
        int t1 = 0,t0 = 0;
        int j = 0;
        int ans = 0;
        for(int i = 0;i<n;i++){
            if(s.charAt(i)=='1')t1++;
            else t0++;

            if(t1<(t0*t0)){
                if(s.charAt(j)=='1')t1--;
                else t0--;
                j++;
            }
            for(int k = j;k<=i;k++){
                
            }
        }
        return ans;
    }
}