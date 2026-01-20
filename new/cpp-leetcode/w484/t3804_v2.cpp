#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  long long centeredSubarrays(vector<int> &nums) {
    int n = nums.size();

    // 1. 预处理前缀和
    // 使用 long long 防止求和溢出。s[i] 表示前 i 个元素的和。
    vector<long long> s(n + 1, 0);
    // 使用 map 记录每一个前缀和数值出现的所有下标（有序存储，方便二分）
    unordered_map<long long, vector<int>> sum_to_indices;
    sum_to_indices[0].push_back(0);

    for (int i = 0; i < n; i++) {
      s[i + 1] = s[i] + nums[i];
      sum_to_indices[s[i + 1]].push_back(i + 1);
    }

    // 2. 预处理每个元素上一次出现的位置
    // 这是去重的关键：子数组中等于和的那个元素，必须是该值在该子数组中第一次出现。
    vector<int> last_occurrence(n, -1);
    unordered_map<int, int> pos_map;
    for (int i = 0; i < n; i++) {
      if (pos_map.count(nums[i])) {
        last_occurrence[i] = pos_map[nums[i]];
      }
      pos_map[nums[i]] = i;
    }

    long long total_count = 0;

    // 3. 遍历每个下标 k，假设 nums[k] 是中心子数组中那个“等于和的元素”
    for (int k = 0; k < n; k++) {
      int val = nums[k];

      // 合法的子数组 [i, j] 必须包含 k，即 i <= k <= j
      // 且为了不重复统计，nums[k] 必须是区间内第一个值为 val 的元素
      // 所以左端点 i 的范围是 (last_occurrence[k], k]
      int left_limit = last_occurrence[k] + 1;
      int right_limit = n - 1;

      // 启发式搜索：比较左侧可选范围和右侧可选范围的大小
      // left_range: [left_limit, k] 之间的 i
      // right_range: [k, right_limit] 之间的 j

      if ((k - left_limit) <= (right_limit - k)) {
        // 情况 A：左边比较短，遍历左边的 i，去右边找合法的 j
        for (int i = left_limit; i <= k; i++) {
          // 我们需要 s[j+1] - s[i] == val  =>  s[j+1] == s[i] + val
          long long target_sum = s[i] + val;
          if (sum_to_indices.count(target_sum)) {
            const auto &indices = sum_to_indices[target_sum];
            // j 的范围是 [k, n-1]，所以 j+1 的范围是 [k+1, n]
            // 在有序下标集合中二分查找在这个范围内的个数
            auto it_start = lower_bound(indices.begin(), indices.end(), k + 1);
            auto it_end = upper_bound(indices.begin(), indices.end(), n);
            total_count += distance(it_start, it_end);
          }
        }
      } else {
        // 情况 B：右边比较短，遍历右边的 j，去左边找合法的 i
        for (int j = k; j <= right_limit; j++) {
          // 我们需要 s[j+1] - s[i] == val  =>  s[i] == s[j+1] - val
          long long target_sum = s[j + 1] - val;
          if (sum_to_indices.count(target_sum)) {
            const auto &indices = sum_to_indices[target_sum];
            // i 的范围是 [left_limit, k]
            auto it_start =
                lower_bound(indices.begin(), indices.end(), left_limit);
            auto it_end = upper_bound(indices.begin(), indices.end(), k);
            total_count += distance(it_start, it_end);
          }
        }
      }
    }

    return total_count;
  }
};
