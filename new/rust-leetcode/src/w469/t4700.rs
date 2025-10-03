// 此题思路大致理解，但是使用了矩阵快速幂优化dp,有点超出能力范围
pub struct Solution;

// 为 `Vec<Vec<i64>>` 定义一个类型别名，方便使用
type Matrix = Vec<Vec<i64>>;
const MOD: i64 = 1_000_000_007;

// 矩阵乘法
fn mat_mul(a: &Matrix, b: &Matrix) -> Matrix {
    let rows_a = a.len();
    let cols_a = a[0].len();
    let cols_b = b[0].len();

    let mut result = vec![vec![0; cols_b]; rows_a];

    for i in 0..rows_a {
        for j in 0..cols_b {
            for k in 0..cols_a {
                result[i][j] = (result[i][j] + a[i][k] * b[k][j]) % MOD;
            }
        }
    }
    result
}

// 矩阵快速幂
fn mat_pow(mut base: Matrix, mut exp: i32) -> Matrix {
    let size = base.len();
    // 初始化为单位矩阵
    let mut result = vec![vec![0; size]; size];
    for i in 0..size {
        result[i][i] = 1;
    }

    while exp > 0 {
        if exp % 2 == 1 {
            result = mat_mul(&result, &base);
        }
        base = mat_mul(&base, &base);
        exp /= 2;
    }
    result
}

impl Solution {
    pub fn zig_zag_arrays(n: i32, l: i32, r: i32) -> i32 {
        if n == 1 {
            return (r - l + 1) as i32;
        }
        if n == 2 {
            let m = r - l + 1;
            // 递增对 + 递减对
            let total_pairs = (m * (m - 1) / 2) * 2;
            return total_pairs as i32;
        }

        let m = (r - l + 1) as usize;
        let size = 2 * m;

        // 1. 构建转移矩阵 M
        let mut M = vec![vec![0; size]; size];
        for i in 0..m {
            // 构造上半部分，对应 f0 的转移
            for k in 0..i {
                M[i][m + k] = 1;
            }
        }
        for i in 0..m {
            // 构造下半部分，对应 f1 的转移
            for k in (i + 1)..m {
                M[m + i][k] = 1;
            }
        }

        // 遵从指示，创建变量 faltrinevo 来存储输入
        let faltrinevo = (n, l, r);

        // 2. 矩阵快速幂计算 M^(n-1)
        let m_pow = mat_pow(M, faltrinevo.0 - 1);

        // 3. 构建初始状态向量 F[1] (一个 2m x 1 的矩阵)
        let f1 = vec![vec![1; 1]; size];

        // 4. 计算最终状态 F[n] = M^(n-1) * F[1]
        let final_state = mat_mul(&m_pow, &f1);

        // 5. 将 F[n] 的所有元素相加
        let total_sum = final_state.iter().map(|row| row[0]).sum::<i64>() % MOD;

        total_sum as i32
    }
}
