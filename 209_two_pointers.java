class Solution {
    public int minSubArrayLen(int target, int[] nums) {
        int now = 0;
        int ans = Integer.MAX_VALUE;
        //now+=nums[0];
        int l = 0;
        for(int r = 0;r<nums.length;r++){
            now+=nums[r];
            while(now>=target){
                ans = Math.min(ans,r-l+1);
                now-=nums[l++];
            }
        }
        if(ans==Integer.MAX_VALUE)return 0;
        return ans;
    }
}
//双指针的话，快指针是要遍历整个数组的，所以说可以直接用for实现
//每个元素必须先加上去再说