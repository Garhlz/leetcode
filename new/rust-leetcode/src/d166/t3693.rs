struct Solution;
impl Solution {
    pub fn climb_stairs(n: i32, costs: Vec<i32>) -> i64 {
        let n_usize = n as usize;
        let mut dp = vec![i64::MAX; n_usize + 1];

        dp[0] = 0;

        for i in 1..=n_usize {
            let cur_cost = costs[i - 1] as i64;
            if i >= 1 {
                let cost = dp[i - 1] + cur_cost + 1 as i64;
                dp[i] = dp[i].min(cost);
            }
            if i >= 2 {
                let cost = dp[i - 2] + cur_cost + 4 as i64;
                dp[i] = dp[i].min(cost);
            }
            if i >= 3 {
                let cost = dp[i - 3] + cur_cost + 9 as i64;
                dp[i] = dp[i].min(cost);
            }
        }
        dp[n_usize]
    }
}

#[cfg(test)]
mod tests {
    use super::Solution;

    #[test]
    fn test_example_1() {
        let n = 4;
        let costs = vec![1, 2, 3, 4];
        assert_eq!(Solution::climb_stairs(n, costs), 13);
    }

    #[test]
    fn test_example_2() {
        let n = 4;
        let costs = vec![5, 1, 6, 2];
        assert_eq!(Solution::climb_stairs(n, costs), 11);
    }

    #[test]
    fn test_example_3() {
        let n = 3;
        let costs = vec![9, 8, 3];
        assert_eq!(Solution::climb_stairs(n, costs), 12);
    }
}
