class Solution {
    public int removeDuplicates(int[] nums) {
        int p = 0,q = 1;
        int n = nums.length;
        if(n==0)return 0;
        while(q<n){
            if(nums[p]!=nums[q]&&q-p>1){
                nums[p+1] = nums[q];
                p++;
            }
            q++;
        }
        return p+1;
    }
}
//注意初始双指针的数值条件