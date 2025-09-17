class solution{
    public int[] shortestDistanceAfterQueries(int n,int[][] queries){
        List<Integer>[] from = new ArrayList[n];
        Arrays.setAll(from, i->new ArrayList<>());
        int[] f = new int[n];
        for(int i = 1;i<n;i++){
            f[i] = i;
        }
        int[ ] ans = new int[queries.length];
        for(int i = 0;i<queries.length;i++){
            int l = queries[i][0],r = queries[i][1];
            from[r].add(l);
            if(f[l] + 1 < f[r]){
                f[r] = f[l] + 1;
                for(int j = r+1;j<n;j++){
                    f[j] = Math.min(f[j],f[j-1]+1);
                    for(int k : from[j]){
                        f[j] = Math.min(f[j], f[k] + 1);
                    }
                }
            }
            ans[i] = f[n-1];
        }
        return ans;
    }
}