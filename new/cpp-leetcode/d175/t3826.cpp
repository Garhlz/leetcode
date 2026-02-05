由于子数组的值是个分数，不好处理，我们可以先计算分子之和（或者说，把子数组的值乘以 2），最后返回时再除以 2。 划分型
    DP

        本题是标准的划分型 DP。根据 动态规划题单「§5.3 约束划分个数」，定义 fK,
    i​ 表示把长为 i 的前缀[0, i−1] 划分成恰好 K 个子数组的分数（乘以 2）。

    枚举最后一段子数组的左端点 j，问题变成把前缀[0, j−1] 划分成恰好
        K−1 个子数组的分数（乘以 2），即 fK−1,
    j​。

        设 nums 的前缀和数组为 s。关于 s 数组的定义，请看 前缀和。

            把子数组[j, i−1] 的元素和用前缀和表示，即 si​−sj​。

                子数组的值（乘以 2）为(si​−sj​)(si​−sj​ + 1)

                    取最小值，有 fK,
    i​ = j = 0mini−1​fK−1,
    j​ + (si​−sj​)(si​−sj​ + 1)

               初始值 f0,
    0​ = 0，fi,
    i−1​ = ∞。注意不需要初始化 K < i−1 的状态，因为我们不会访问这些状态。

               答案为 fk,
    n​。

    这样做的时间复杂度是 O(n2k)，太慢了，如何优化？ 斜率优化（凸包优化）

    注：以下内容基于点积，和斜率优化本质是一样的。我推荐从点积的角度理解，相比斜率的角度，不需要做麻烦的式子变形，更方便。

    前置知识：二维计算几何，凸包，Andrew 算法。

    把转移方程中的括号展开，得 fK,
    i​ = si2​ + si​ + j = 0mini−1​fK−1,
    j​−2si​sj​ + sj2​−sj​

        把其中的 fK−1,
    j​−2si​sj​ + sj2​−sj​

        改成点积的形式，这样我们能得到来自几何意义上的观察。

        设向量 vj​ = (sj​, fK−1, j​ + sj2​−sj​)。

    设向量 p = (−2si​, 1)。

    那么我们求的是 j =
        0mini−1​p⋅vj​

        根据点积的几何意义，我们求的是 vj​ 在 p 方向上的投影长度，再乘以 p
        的模长 ∣∣p∣∣。由于 ∣∣p∣∣ 是个定值，所以要最小化投影长度。

        考虑 vj​ 的凸包（用 Andrew
        算法计算），在凸包内的点，比凸包顶点的投影长度长（注意 p
        在凸包外面）。所以只需考虑凸包顶点。由于下凸包的投影长度比上凸包的短，所以只需考虑下凸包。

        由于 sj​ 是单调递增的，求下凸包无需排序。

        这样有一个很好的性质：从左到右遍历凸包顶点，p⋅vj​
        会先变小再变大（单峰函数）。那么要计算最小值，就类似
        852. 山脉数组的峰顶索引，二分首个「上坡」的位置，见 我的题解。

        实际上不需要二分。由于 −2si​ 是单调递减的，可以用单调队列维护凸包。

        lc3826
        - c.png

          如上图所示，设向量 p 的垂线与凸包的交点为 A，那么 OA 到 p
          的投影长度最短。

          当向量 p 向左旋转时，交点 A 在凸包上会向右移动。

          struct vec {
  long long x, y;
};

vec sub(vec a, vec b) { return vec{a.x - b.x, a.y - b.y}; }

long long dot(vec a, vec b) { return a.x * b.x + a.y * b.y; }

// 如果乘法会溢出，用 __int128
__int128 det(vec a, vec b) { return (__int128)a.x * b.y - (__int128)a.y * b.x; }

class Solution {
public:
  long long minPartitionScore(vector<int> &nums, int k) {
    int n = nums.size();
    vector<int> sum(n + 1); // nums 的前缀和
    partial_sum(nums.begin(), nums.end(), sum.begin() + 1);

    vector<long long> f(n + 1, LLONG_MAX / 2);
    f[0] = 0;

    vector<vec> q(n - k + 2);

    for (int K = 1; K <= k; K++) {
      int head = 0, tail = 0; // 模拟 deque

      long long s = sum[K - 1];
      q[tail++] = vec{s, f[K - 1] + s * s - s};

      for (int i = K; i <= n - (k - K); i++) { // 其他子数组的长度至少是 1
        s = sum[i];
        vec p = {-2 * s, 1};
        while (tail - head > 1 && dot(p, q[head]) >= dot(p, q[head + 1])) {
          head++;
        }

        vec v{s, f[i] + s * s - s};
        f[i] = dot(p, q[head]) + s * s + s;

        while (tail - head > 1 &&
               det(sub(q[tail - 1], q[tail - 2]), sub(v, q[tail - 1])) <= 0) {
          tail--;
        }
        q[tail++] = v;
      }
    }

    return f[n] / 2;
  }
};
