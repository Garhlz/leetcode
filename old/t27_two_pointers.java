class Solution {
    public int removeElement(int[] nums, int val) {
        int slowIndex = 0;
        for(int fastIndex = 0;fastIndex<nums.length;fastIndex++){
            if(val!=nums[fastIndex]){
                nums[slowIndex++] = nums[fastIndex];
            }
        }
        return slowIndex;
    }
}
/*
只需要整体扫描一遍即可
对整个数组整体赋值一遍，跳过并且覆盖了需要删除的数字的位置
 */