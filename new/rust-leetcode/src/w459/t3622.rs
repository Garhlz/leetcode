impl Solution {
    pub fn check_divisibility(n: i32) -> bool {
        let mut tmp = n;
        let (mut sum, mut pro) = (0, 1);
        while tmp > 0 {
            sum += tmp % 10;
            pro *= tmp % 10;
            tmp /= 10;
        }
        if n % (pro + sum) == 0 {
            return true;
        } else {
            return false;
        }
    }
}

struct Solution;
