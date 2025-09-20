class Solution {
    public void quick_sort(int[] a,int start,int end){
        if(start>=end)return;
	    int i = start,j = end,m = (start+end)/2;
	    int pivot = a[end];
        while(i<j){
            while(i<j&&a[i]<=pivot)i++;
            a[j] = a[i];
            while(i<j&&a[j]>=pivot)j--;
            a[i] = a[j];
        }
        a[i] = pivot; 
        
        quick_sort(a,start,i-1);
        quick_sort(a,i+1,end); 
    }

    public int[] sortedSquares(int[] nums) {
        for(int i = 0;i<nums.length;i++){
            nums[i] = nums[i]*nums[i];
        }
        quick_sort(nums, 0, nums.length-1);
        return nums;
    }
}