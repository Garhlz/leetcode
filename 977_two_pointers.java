class Solution {
    public int[] sortedSquares(int[] nums) {
        for(int i = 0;i<nums.length;i++)nums[i]*=nums[i];
        int i = 0,j = nums.length-1;
        int[] ans = new int[nums.length];
        int idx = nums.length-1;
        while(i<=j){
            if(nums[i]>nums[j]){
                ans[idx--] = nums[i++];
            }
            else{
                ans[idx--] = nums[j--];
            }
        }
        return ans;
    }
}
//平方之后，相当于两个单调的序列
//每次选择较大的放入序列（从后往前即可）
