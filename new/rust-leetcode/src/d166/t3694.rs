use std::collections::HashSet;
impl Solution {
    pub fn distinct_points(s: String, k: i32) -> i32 {
        let n = s.len();
        let k = k as usize;

        // .chars() 返回一个迭代器，.collect() 收集到一个 Vec<char> 中
        let moves: Vec<char> = s.chars().collect();

        let (mut total_dx, mut total_dy) = (0, 0);

        // 迭代器返回的是&m,需要用模式匹配解引用
        for &m in &moves {
            match m {
                'U' => total_dy += 1,
                'D' => total_dy -= 1,
                'L' => total_dx -= 1,
                'R' => total_dx += 1,
                _ => {} // 注意char还有很多其他选择，这里用_忽略
            }
        }

        let (mut window_dx, mut window_dy) = (0, 0);
        for i in 0..k {
            match moves[i] {
                'U' => window_dy += 1,
                'D' => window_dy -= 1,
                'L' => window_dx -= 1,
                'R' => window_dx += 1,
                _ => {}
            }
        }

        let mut st = HashSet::new();
        st.insert((total_dx - window_dx, total_dy - window_dy));
        for i in k..n {
            let char_in = moves[i];
            let char_out = moves[i - k];
            match char_in {
                'U' => window_dy += 1,
                'D' => window_dy -= 1,
                'L' => window_dx -= 1,
                'R' => window_dx += 1,
                _ => {}
            }
            // 减去旧字符的影响
            match char_out {
                'U' => window_dy -= 1,
                'D' => window_dy += 1,
                'L' => window_dx += 1,
                'R' => window_dx -= 1,
                _ => {}
            }
            st.insert((total_dx - window_dx, total_dy - window_dy));
        }
        st.len() as i32
    }
}

struct Solution;

#[cfg(test)]
mod tests {
    use super::Solution;

    #[test]
    fn test_example_1() {
        let s = "LUL".to_string();
        let k = 1;
        assert_eq!(Solution::distinct_points(s, k), 2);
    }

    #[test]
    fn test_example_2() {
        let s = "UDLR".to_string();
        let k = 4;
        assert_eq!(Solution::distinct_points(s, k), 1);
    }

    #[test]
    fn test_example_3() {
        let s = "UU".to_string();
        let k = 1;
        assert_eq!(Solution::distinct_points(s, k), 1);
    }
}
