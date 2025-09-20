class Solution {
    public int[] getFinalState(int[] nums, int k, int multiplier) {
        int mn = 1000000,pos = -1;
        for(int i = 0;i<k;i++){
            mn = 1000000;
            pos = 0;
            for(int j = 0;j<nums.length;j++){
                if(nums[j]<mn){
                    mn = nums[j];
                    pos = j;
                }
            }
            nums[pos]*=multiplier;
        }
        return nums;
    }
}
