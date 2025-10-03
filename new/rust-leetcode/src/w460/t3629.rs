use std::collections::{HashMap, HashSet, VecDeque};

impl Solution {
    pub fn min_jumps(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        let max_val = *nums.iter().max().unwrap() as usize;

        // 预处理：线性筛判断质数
        let mut is_prime = vec![true; max_val + 1];
        is_prime[0] = false;
        if max_val >= 1 {
            is_prime[1] = false;
        }
        for i in 2..=max_val {
            if is_prime[i] {
                let mut j = i * 2;
                while j <= max_val {
                    is_prime[j] = false;
                    j += i;
                }
            }
        }

        // 建立：质数 p -> 所有 nums[j] % p == 0 的下标 j
        let mut teleport_map: HashMap<i32, Vec<usize>> = HashMap::new();
        for (i, &x) in nums.iter().enumerate() {
            // 对每个质数 p（p <= sqrt(x)），如果 x % p == 0，则建立映射
            for p in 2..=((x as f64).sqrt() as i32) {
                if x % p == 0 {
                    if is_prime[p as usize] {
                        teleport_map.entry(p).or_default().push(i);
                    }
                    let q = x / p;
                    if q != p && is_prime[q as usize] {
                        teleport_map.entry(q).or_default().push(i);
                    }
                }
            }
            if x > 1 && is_prime[x as usize] {
                teleport_map.entry(x).or_default().push(i);
            }
        }

        // BFS
        let mut visited = vec![false; n];
        let mut used_teleport = HashSet::new();
        let mut q = VecDeque::new();
        visited[0] = true;
        q.push_back(0);
        let mut steps = 0;

        while !q.is_empty() {
            for _ in 0..q.len() {
                let i = q.pop_front().unwrap();
                if i == n - 1 {
                    return steps;
                }

                // 相邻跳
                for &j in &[i.wrapping_sub(1), i + 1] {
                    if j < n && !visited[j] {
                        visited[j] = true;
                        q.push_back(j);
                    }
                }

                let val = nums[i];
                if is_prime[val as usize] && !used_teleport.contains(&val) {
                    if let Some(list) = teleport_map.get(&val) {
                        for &j in list {
                            if !visited[j] {
                                visited[j] = true;
                                q.push_back(j);
                            }
                        }
                    }
                    used_teleport.insert(val);
                }
            }
            steps += 1;
        }

        -1
    }
}

pub struct Solution;
