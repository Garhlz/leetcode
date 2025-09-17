import java.util.PriorityQueue;

class Solution {
    private static final int MOD = 1000000007;
    public int[] getFinalState(int[] nums, int k, int multiplier) {
        if(multiplier == 1){
            return nums;
        }

        int n = nums.length;
        int mx = 0;
        PriorityQueue<Long[]> pq = new PriorityQueue<>(new Comparator<Long[]>(){
            public int compare(Long[] a,Long[] b){
                if(a[0]!=b[0]){
                    return Long.compare(a[0],b[0]);
                }else{
                    return Long.compare(a[1],b[1]);
                }
            }
        });
        int n = nums.length;
        int mx = 0;
        for(int i = 0;i<n;i++){
            mx = Math.max(mx,nums[i]);
            pq.offer(new Long[]{nums[i],i});//直接静态复制，就是一个pair
        }

        while(k>0 && pq.peek()[0] < mx){
            Long[] p = pq.poll();//poll会弹出，peek不会弹出
            p[0] *= multiplier;
            pq.offer(p);
            k--;
        }

        for(int i = 0;i<n;i++){
            Long[] p = pq.poll();
            nums[(int) p[1]] = (int) (p[0] % MOD * pow(multiplier, k / n + (i < k % n ? 1 : 0)) % MOD);
        }
        return nums;
    }

    private long pow(int a,int b){
        long res = 1;
        while(b>0){
            if(b&1==1){
                res = res*a%MOD;
                a = a*a%MOD;
                b>>=1;
            }
        }
        return res;
    }
}