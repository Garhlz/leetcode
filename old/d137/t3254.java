class Solution {
    public int[] resultsArray(int[] a, int k) {
        int n = a.length;
        int ans[] = new int[n-k+1];
        for(int i = 0;i<n-k+1;i++){
            int flag = 1;
            for(int j = i;i<i+k-1;j++){
                if(a[j]+1!=a[j+1]){
                    flag = 0;
                    break;
                }
            }
            if(flag==1){
                ans[i] = a[i+k-1];
            }else ans[i] = -1;
        }
        return ans;
    }
}