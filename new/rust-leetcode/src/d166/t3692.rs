use std::collections::HashMap;
impl Solution {
    pub fn majority_frequency_group(s: String) -> String {
        let mut char_counts = HashMap::new();
        for c in s.chars() {
            *char_counts.entry(c).or_insert(0) += 1;
        }

        let mut freq_groups: HashMap<i32, Vec<char>> = HashMap::new();
        for (character, freq) in char_counts {
            freq_groups.entry(freq).or_default().push(character);
        }

        let mut max_size = 0;
        let mut best_k = 0;
        let mut result_chars = Vec::new();
        // k表示出现频率，如果数组大小相同，取频率更大的那个
        for (k, chars) in freq_groups {
            let current_size = chars.len();
            if current_size > max_size {
                max_size = current_size;
                best_k = k;
                result_chars = chars;
            } else if current_size == max_size {
                if k > best_k {
                    best_k = k;
                    result_chars = chars;
                }
            }
        }

        result_chars.sort_unstable();
        result_chars.into_iter().collect()
    }
}

struct Solution;

#[cfg(test)]
mod tests {
    // 导入父模块的 Solution
    use super::Solution;

    #[test]
    fn test_simple_equal_frequency() {
        // 这个用例测试最简单、频率相同的情况
        assert_eq!(
            Solution::majority_frequency_group("aaabbb".to_string()),
            "ab".to_string()
        );
    }

    #[test]
    fn test_from_example_1() {
        // 这个用例来自 LeetCode 的示例1
        assert_eq!(
            Solution::majority_frequency_group("aaabbbccdddde".to_string()),
            "ab".to_string()
        );
    }

    #[test]
    fn test_tie_break_with_higher_k() {
        // 这个用例专门测试 “组大小并列时，选择频率k更大” 的规则
        // {a,b,c} 组大小为 3, k=3
        // {d} 组大小为 1, k=4
        // {e} 组大小为 1, k=1
        // 最终应该选择 {a,b,c} 组
        assert_eq!(
            Solution::majority_frequency_group("aaabbbcccdddde".to_string()),
            "abc".to_string() // 注意：根据规则，这个用例的正确答案应该是 "abc" 而不是 "ab"
        );
    }
}
