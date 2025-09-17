impl Solution {
    pub fn insert(intervals: Vec<Vec<i32>>, new_interval: Vec<i32>) -> Vec<Vec<i32>> {
        let mut a = intervals;
        let b = new_interval;
        let l = a.partition_point(|x| x[1] < b[0]);
        let r = a.partition_point(|x| x[0] <= b[1]);
        if l == r {
            a.insert(l, b);
        }else{
            a[l] = vec![b[0].min(a[l][0]), b[1].max(a[r-1][1])];
            a.drain(l+1..r);
        }
        a
    }
}