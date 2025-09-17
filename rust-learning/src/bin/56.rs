impl Solution { // 理解错误,是要合并区间,如果区间相邻不可,重叠才可
    pub fn merge(intervals: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let mut a = intervals;
        a.sort_by(|a, b| a[0].cmp(&b[0]));
        let mut ans = vec![];
        let mut l = a[0][0];
        let mut r = a[0][1];
        for now in 0..a.len() {
            if a[now][0] >= l && a[now][0] <= r {
                r = if a[now][1] > r {a[now][1]} else {r};
            }
            else{
                ans.push(vec![l,r]);
                l = a[now][0];
                r = a[now][1];
            }
        }
        ans.push(vec![l,r]);
        ans
    }
}