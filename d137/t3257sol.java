class Solution {
    public long maximumValueSum(int[][] board) {
        int m = board.length;
        int n = board[0].length;
        int[][][] suf = new int[m][3][2];
        int[][] p = new int[3][2]; // 最大、次大、第三大
        for (int[] pr : p) {
            pr[0] = Integer.MIN_VALUE;
        }
        for (int i = m - 1; i > 1; i--) {
            update(board[i], p);
            for (int j = 0; j < 3; j++) {
                suf[i][j][0] = p[j][0];
                suf[i][j][1] = p[j][1];
            }
        }

        long ans = Long.MIN_VALUE;
        for (int[] pr : p) {
            pr[0] = Integer.MIN_VALUE; // 重置，计算 pre
        }
        for (int i = 1; i < m - 1; i++) {
            update(board[i - 1], p);
            for (int j = 0; j < n; j++) { // 第二个车
                for (int[] a : p) { // 第一个车
                    for (int[] b : suf[i + 1]) { // 第三个车
                        if (a[1] != j && b[1] != j && a[1] != b[1]) { // 没有同列的车
                            ans = Math.max(ans, (long) a[0] + board[i][j] + b[0]);
                            break;
                        }
                    }
                }
            }
        }
        return ans;
    }

    private void update(int[] row, int[][] p) {
        for (int j = 0; j < row.length; j++) {
            int x = row[j];
            if (x > p[0][0]) {
                if (p[0][1] != j) { // 如果相等，仅更新最大
                    if (p[1][1] != j) { // 如果相等，仅更新最大和次大
                        p[2] = p[1];
                    }
                    p[1] = p[0];
                }
                p[0] = new int[]{x, j};
            } else if (x > p[1][0] && j != p[0][1]) {
                if (p[1][1] != j) { // 如果相等，仅更新次大
                    p[2] = p[1];
                }
                p[1] = new int[]{x, j};
            } else if (x > p[2][0] && j != p[0][1] && j != p[1][1]) {
                p[2] = new int[]{x, j};
            }
        }
    }
}

