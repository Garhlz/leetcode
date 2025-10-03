use std::vec;

impl Solution {
    pub fn num_of_subsequences(s: String) -> i64 {
        let n = s.len();
        let chars: Vec<char> = s.chars().collect();
        let (mut pre_l, mut pre_lc, mut pre_lct) = (0, 0, 0);

        let mut pre_l_arr = vec![0; n];
        let mut suf_t_arr = vec![0; n];

        let mut now = 0i64;
        for i in 0..n {
            if i > 0 {
                pre_l_arr[i] = pre_l_arr[i - 1];
            }
            if chars[i] == 'L' {
                pre_l += 1;
                pre_l_arr[i] += 1;
            } else if chars[i] == 'C' {
                pre_lc += pre_l;
            } else if chars[i] == 'T' {
                pre_lct += pre_lc;
                now = now.max(pre_lc);
            }
        }
        now = now.max(pre_lc);
        let (mut suf_t, mut suf_ct) = (0, 0);
        for i in (0..n).rev() {
            if i < n - 1 {
                suf_t_arr[i] = suf_t_arr[i + 1];
            }
            if chars[i] == 'T' {
                suf_t += 1;
                suf_t_arr[i] += 1;
            } else if chars[i] == 'C' {
                suf_ct += suf_t;
            } else if chars[i] == 'L' {
                now = now.max(suf_ct);
            }
        }
        now = now.max(suf_ct);

        for i in 0..n - 1 {
            let total = (pre_l_arr[i] as i64) * (suf_t_arr[i + 1] as i64);
            now = now.max(total);
        }
        let mut ans = 0i64;
        ans = now + pre_lct;
        ans
    }
}

struct Solution;

#[cfg(test)]
mod tests {
    use crate::w460::t3628::Solution;

    #[test]
    fn test_1() {
        assert_eq!(Solution::num_of_subsequences("LT".to_string()), 1);
    }
}
