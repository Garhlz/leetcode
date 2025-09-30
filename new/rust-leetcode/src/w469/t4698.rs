impl Solution {
    pub fn split_array(nums: Vec<i32>) -> i64 {
        let n = nums.len();
        let mut ans = i64::MAX;
        let mut is_up = vec![false; n];
        let mut is_down = vec![false; n];
        let mut pre: Vec<i64> = vec![0; n];
        pre[0] = nums[0] as i64;
        is_up[0] = true;
        let mut flag = 1;
        for i in 1..n {
            pre[i] = pre[i - 1] + nums[i] as i64;
            if nums[i] > nums[i - 1] && flag == 1 {
                is_up[i] = true;
            } else {
                flag = 0;
            }
        }
        is_down[n - 1] = true;
        flag = 1;
        for i in (1..n - 1).rev() {
            if nums[i] > nums[i + 1] && flag == 1 {
                is_down[i] = true;
            } else {
                flag = 0;
            }
        }
        let abs = |a: i64| if a > 0 { a } else { -a };
        for i in 0..n - 1 {
            if is_up[i] && is_down[i + 1] {
                ans = ans.min(abs((pre[i] - (pre[n - 1] - pre[i])) as i64));
            }
        }
        if ans == i64::MAX {
            return -1 as i64;
        }
        ans
    }
}

struct Solution;

mod tests {
    use std::vec;

    // 导入父模块的 Solution
    use super::Solution;

    #[test]
    fn test_1() {
        // 这个用例测试最简单、频率相同的情况
        assert_eq!(Solution::split_array(vec![1, 3, 2]), 2);
    }

    #[test]
    fn test_2() {
        // 这个用例测试最简单、频率相同的情况
        assert_eq!(Solution::split_array(vec![1, 2, 4, 3]), 4);
    }

    #[test]
    fn test_3() {
        // 这个用例测试最简单、频率相同的情况
        assert_eq!(Solution::split_array(vec![3, 1, 2]), -1);
    }
}
