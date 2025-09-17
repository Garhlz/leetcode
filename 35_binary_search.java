class Solution {
    public int searchInsert(int[] nums, int target) {
        int l = 0,r = nums.length-1;
        int m = (l+r)/2;
        while(l<=r){
            m = (l+r)/2;
            if(nums[m]<target){
                l = m+1;
            }
            else if(nums[m]>target){
                r = m-1;
            }
            else{
                return m;
            }
        }
        return r+1;
    }
}