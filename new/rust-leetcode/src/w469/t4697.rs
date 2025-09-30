impl Solution {
    pub fn decimal_representation(n: i32) -> Vec<i32> {
        let mut ans = Vec::new();
        let mut n = n;
        let mut now = 1;
        while n > 0 {
            if n % 10 != 0 {
                ans.push((n % 10) * now);
            }
            n /= 10;
            now *= 10;
        }
        ans.reverse();
        ans
    }
}

struct Solution;

#[cfg(test)]
mod tests {
    use std::vec;

    // 导入父模块的 Solution
    use super::Solution;

    #[test]
    fn test_1() {
        // 这个用例测试最简单、频率相同的情况
        assert_eq!(Solution::decimal_representation(321), vec![300, 20, 1]);
    }

    #[test]
    fn test_2() {
        assert_eq!(Solution::decimal_representation(3002), vec![3000, 2]);
    }
}
