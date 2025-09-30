use std::collections::HashMap;
struct UnionFind {
    parent: Vec<usize>,
}

impl UnionFind {
    fn new(n: usize) -> Self {
        let parent = (0..n).collect();
        Self { parent }
    }

    fn find(&mut self, i: usize) -> usize {
        if self.parent[i] == i {
            return i;
        }
        self.parent[i] = self.find(self.parent[i]);
        self.parent[i]
    }

    fn union(&mut self, i: usize, j: usize) {
        let fa1 = self.find(i);
        let fa2 = self.find(j);
        if fa1 != fa2 {
            self.parent[fa1] = fa2;
        }
    }
}

impl Solution {
    pub fn max_alternating_sum(nums: Vec<i32>, swaps: Vec<Vec<i32>>) -> i64 {
        let n = nums.len();
        let mut uf = UnionFind::new(n);
        for swap in swaps {
            uf.union(swap[0] as usize, swap[1] as usize);
        }

        let mut indices: HashMap<usize, Vec<usize>> = HashMap::new();
        let mut values: HashMap<usize, Vec<i64>> = HashMap::new();

        for i in 0..n {
            let fa = uf.find(i);
            indices.entry(fa).or_default().push(i);
            values.entry(fa).or_default().push(nums[i] as i64);
        }

        let mut result = 0 as i64;

        for (fa, indice) in indices {
            let mut value = values.remove(&fa).unwrap();
            // .sort_unstable_by 接受一个闭包作为排序规则
            // b.cmp(a) 相当于排序之后 b < a, 也就是降序
            value.sort_unstable_by(|a, b| b.cmp(a));
            let mut even_pos_cnt = 0;

            for &i in &indice {
                if i % 2 == 0 {
                    even_pos_cnt += 1;
                }
            }

            // .iter() 创建一个非消耗性的迭代器，只是借用集合中的元素
            let mut value_iter = value.iter();
            for _ in 0..even_pos_cnt {
                // .next() 返回迭代器的下一个元素的 Option<&T>， if let Some(&val) = ... 解引用得到 T
                if let Some(&val) = value_iter.next() {
                    result += val;
                }
            }
            // 注意这里是直接减去剩下的值， 直接遍历剩下的value_iter
            for &val in value_iter {
                result -= val;
            }
        }
        result
    }
}

struct Solution;

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_example_1() {
        let nums = vec![1, 2, 3];
        let swaps = vec![vec![0, 2], vec![1, 2]];
        assert_eq!(Solution::max_alternating_sum(nums, swaps), 4);
    }

    #[test]
    fn test_example_2() {
        let nums = vec![1, 1, 1, 2];
        let swaps = vec![vec![1, 3]];
        assert_eq!(Solution::max_alternating_sum(nums, swaps), -1);
    }
}
