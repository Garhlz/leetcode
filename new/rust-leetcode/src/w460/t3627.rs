impl Solution {
    pub fn maximum_median_sum(nums: Vec<i32>) -> i64 {
        let mut nums = nums;
        nums.sort_unstable();
        let n = nums.len();
        let mut ans = 0i64;
        for i in ((n / 3)..=n - 2).rev().step_by(2) {
            ans += nums[i] as i64;
        }
        ans
    }
}

struct Solution;

#[cfg(test)]
mod tests {
    use super::Solution;
    #[test]
    fn test_1() {
        assert_eq!(Solution::maximum_median_sum(vec![1000, 1, 1000]), 1000);
    }

    #[test]
    fn test_2() {
        assert_eq!(Solution::maximum_median_sum(vec![2, 1, 3, 2, 1, 3]), 5);
    }
}
