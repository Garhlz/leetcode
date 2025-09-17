
class Solution {
    public static final int MOD = 1000000007;
    
    public int countOfPairs(int[] nums) {
        int n = nums.length;
        int m = nums[n-1];
        for(int i = 1;i<n;i++){
            int x = nums[i] - nums[i-1];
            if(x>0)m-=x;
        }
        return combination(n+m,n);
    }
    
    public static int combination(int n, int k) {
        // 边界条件
        if (k == 0 || k == n) {
            return 1;
        }
        if (k > n) {
            return 0;
        }

        // 检查是否已经计算过这个子问题
        if (!memo.containsKey(n) || !memo.get(n).containsKey(k)) {
            // 递归计算
            int result = combination(n - 1, k - 1) + combination(n - 1, k) % MOD;
            // 存储结果
            if (!memo.containsKey(n)) {
                memo.put(n, new HashMap<>());
            }
            memo.get(n).put(k, result);
        }
        return memo.get(n).get(k) % MOD;
    }

    // 存储已经计算过的组合数
    private static Map<Integer, Map<Integer, Integer>> memo = new HashMap<>();
}