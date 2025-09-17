class Solution{
    public void moveZeroes(int[ ] nums){
        int n = nums.length;
        int l = 0,r = 0;
        while(r<n){
            if(nums[r]!=0){
                nums[l++] = nums[r];
            }
            r++;
        }
        for(int i = l;i<n;i++)nums[i] = 0;
    }
}
//可以直接交换，也可以从慢指针开始继续扫描一遍