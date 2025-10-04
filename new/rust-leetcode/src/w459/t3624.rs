struct FenwickTree {
    data: Vec<i32>,
}

impl FenwickTree {
    // 构造一个大小为 size 的树状数组
    fn new(size: usize) -> Self {
        Self {
            data: vec![0; size + 1],
        } // 使用 1-based indexing，所以大小需要 +1
    }

    // 在 idx 位置增加 delta
    fn add(&mut self, mut idx: usize, delta: i32) {
        idx += 1; // 转换为 1-based
        while idx < self.data.len() {
            self.data[idx] += delta;
            idx += idx & idx.wrapping_neg(); // 跳转到下一个相关的索引
        }
    }

    // 查询从 0 到 idx 的前缀和
    fn query(&self, mut idx: usize) -> i32 {
        idx += 1; // 转换为 1-based
        let mut sum = 0;
        while idx > 0 {
            sum += self.data[idx];
            idx -= idx & idx.wrapping_neg(); // 跳转到上一个相关的索引
        }
        sum
    }

    // 查询 [l, r] 区间的和
    fn query_range(&self, l: usize, r: usize) -> i32 {
        let sum_r = self.query(r);
        let sum_l_minus_1 = if l > 0 { self.query(l - 1) } else { 0 };
        sum_r - sum_l_minus_1
    }
}

impl Solution {
    fn calculate_depth(mut n: i64) -> usize {
        for d in 0..6 {
            if n == 1 {
                return d;
            }
            n = n.count_ones() as i64;
        }
        6
    }

    pub fn popcount_depth(nums: Vec<i64>, queries: Vec<Vec<i64>>) -> Vec<i32> {
        let n = nums.len();

        let mut depths: Vec<usize> = nums.iter().map(|&x| Self::calculate_depth(x)).collect();

        // 核心数据结构变为 Vec<FenwickTree>
        let mut mp: Vec<FenwickTree> = (0..7).map(|_| FenwickTree::new(n)).collect();
        for (i, &d) in depths.iter().enumerate() {
            mp[d].add(i, 1); // 在对应深度的树状数组中，将位置 i 标记为 1
        }

        let mut ans: Vec<i32> = Vec::new();

        for query in queries {
            if query[0] == 1 {
                // 类型 1: 区间查询 [1, l, r, k]
                let l = query[1] as usize;
                let r = query[2] as usize;
                let k = query[3] as usize;

                // 直接查询树状数组的区间和，复杂度 O(logN)
                let count = mp[k].query_range(l, r);
                ans.push(count);
            } else {
                // 类型 2: 单点更新 [2, idx, val]
                let idx = query[1] as usize;
                let val = query[2] as i64;

                let old_depth = depths[idx];
                let new_depth = Self::calculate_depth(val);

                // 只有当深度确实改变时才需要更新
                if old_depth != new_depth {
                    // 在旧深度的树状数组中，将位置 i 的标记 -1（相当于移除）
                    mp[old_depth].add(idx, -1);
                    // 在新深度的树状数组中，将位置 i 的标记 +1（相当于添加）
                    mp[new_depth].add(idx, 1);
                    // 更新我们的深度缓存
                    depths[idx] = new_depth;
                }
            }
        }

        ans
    }
}

pub struct Solution;
