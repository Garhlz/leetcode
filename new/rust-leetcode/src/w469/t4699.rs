impl Solution {
    pub fn zig_zag_arrays(n: i32, l: i32, r: i32) -> i32 {
        const MOD: i64 = 1000000007;
        // 表示长度[0,m-1]
        let m = (r - l + 1) as usize;
        // f0表示以i结尾递增的个数，f1表示以i结尾递减的个数
        let mut f0 = vec![1i64; m];
        let mut f1 = vec![1i64; m];

        for _ in 2..=n {
            // 前缀和数组
            let mut s0 = vec![0i64; m];
            let mut s1 = vec![0i64; m];

            s0[0] = f0[0];
            s1[0] = f1[0];
            // 改为0base的前缀和
            for j in 1..m {
                s0[j] = (s0[j - 1] + f0[j]) % MOD;
                s1[j] = (s1[j - 1] + f1[j]) % MOD;
            }

            let mut new_f0 = vec![0i64; m];
            let mut new_f1 = vec![0i64; m];

            for j in 0..m {
                // f1的前缀和
                if j != 0 {
                    // 此处取0没有意义
                    new_f0[j] = s1[j - 1];
                }

                let suf_f0 = (s0[m - 1] - s0[j] + MOD) % MOD;
                // f0的后缀和
                new_f1[j] = suf_f0
            }
            f0 = new_f0;
            f1 = new_f1;
        }
        let ans = (f0.iter().sum::<i64>() + f1.iter().sum::<i64>()) % MOD;
        ans as i32
    }
}

struct Solution;

#[cfg(test)]
mod tests {
    use super::Solution;
    #[test]
    fn test_example_1() {
        assert_eq!(Solution::zig_zag_arrays(3, 4, 5), 2);
    }

    #[test]
    fn test_example_2() {
        assert_eq!(Solution::zig_zag_arrays(3, 1, 3), 10);
    }
}
