class Solution {
    public int removeElement(int[] nums, int val) {
        int len = nums.length;
        for(int i = 0;i<len;i++){
            int now = nums[i];
            if(now==val){
                for(int j = i+1;j<len;j++){
                    nums[j-1] = nums[j];
                }
                i--;
                len--;
            }
        }
        return len;
    }
}