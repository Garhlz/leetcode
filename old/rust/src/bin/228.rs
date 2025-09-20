impl Solution {
    pub fn summary_ranges(nums: Vec<i32>) -> Vec<String> {
        let n = nums.len();
        if n == 0{
            return vec![];
        }
        let mut ans : Vec<(i32,i32)> = vec![];
        let mut last = 0;
        for i in 1..n {
            if nums[i] != nums[i-1] + 1{
                ans.push((nums[last], nums[i-1]));
                last = i;
            }
        }
        ans.push((nums[last], nums[n-1]));
        let mut result = vec![];
        for (i,j) in ans {
            if i == j {
                result.push(format!("{}",i));
            }
            else {
                result.push(format!("{}->{}",i,j));
            }
        }
        result
    }
}