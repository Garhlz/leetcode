use std::collections::HashMap;
impl Solution {
    pub fn count_trapezoids(points: Vec<Vec<i32>>) -> i32 {
        const MOD: i64 = 1000000007; // 注意取模的问题，这里全都要模数，并且返回i32
        let mut map: HashMap<i32, i32> = HashMap::new();
        for pair in points {
            let count = map.entry(pair[1]).or_insert(0); // 返回的是可变引用
            *count += 1;
        }
        let mut arr: Vec<i64> = Vec::new();
        for (_, cnt) in map {
            // 直接for遍历即可，这里用的是不可变引用
            let mut tmp = cnt as i64;
            tmp = (tmp * (tmp - 1) / 2) % MOD;
            arr.push(tmp);
        }
        let n = arr.len();
        let mut sum = arr[n - 1];
        let mut ans = 0;
        for i in (0..n - 1).rev() {
            ans = (ans + arr[i] * sum) % MOD;
            sum = (sum + arr[i]) % MOD;
        }
        ans as i32
    }
}

struct Solution;

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test1() {
        assert_eq!(
            Solution::count_trapezoids(vec![
                vec![1, 0],
                vec![2, 0],
                vec![3, 0],
                vec![2, 2],
                vec![3, 2]
            ]),
            3
        );
    }
}
