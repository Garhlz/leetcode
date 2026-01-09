#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findKthLargest(std::vector<int> &nums, int k)
    {
        int target = nums.size() - k;
        return quickSelect(nums, 0, nums.size() - 1, target);
    }
private:
    int quickSelect(std::vector<int> &nums, int left, int right, int k){
        if(left == right)return nums[left];

        int pivotIndex = left + rand() % (right - left + 1);
        pivotIndex = partition(nums, left, right, pivotIndex);

        if(pivotIndex == k){
            return nums[k];
        } else if(k < pivotIndex){
            return quickSelect(nums, left, pivotIndex - 1, k);
        } else{
            return quickSelect(nums, pivotIndex + 1, right, k);
        }
        
    }

    int partition(vector<int> &nums, int left, int right, int pivotIndex){
        int pivotValue = nums[pivotIndex];
        swap(nums[pivotIndex], nums[right]);

        int pos = left;

        for(int i = left; i < right; i++) {
            if(nums[i] < pivotValue){
                swap(nums[i], nums[pos]);
                pos++;
            }
        }
        swap(nums[pos], nums[right]);
        return pos;
    }
};
