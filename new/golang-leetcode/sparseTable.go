package golang

// pair 用于存储值和其对应的原始下标
type pair struct {
	val int // 值 (min or max)
	idx int // 原始数组中的下标
}

// SparseTable 结构体封装了所有需要的数据
type SparseTable struct {
	logTable []int    // 预处理的对数表，用于O(1)计算k
	stMax    [][]pair // 存储区间最大值的表
	stMin    [][]pair // 存储区间最小值的表
}

// NewSparseTable 是构造函数，负责所有的预处理工作
func NewSparseTable(nums []int) *SparseTable {
	n := len(nums)
	if n == 0 {
		return nil
	}

	// 1. 预处理log表，logTable[i] = floor(log2(i))
	logTable := make([]int, n+1)
	for i := 2; i <= n; i++ {
		logTable[i] = logTable[i/2] + 1
	}

	// 2. 初始化st表
	// st表的第一维是数组下标，第二维是 2^j 中的 j
	maxLog := logTable[n]
	stMax := make([][]pair, n)
	stMin := make([][]pair, n)
	for i := 0; i < n; i++ {
		stMax[i] = make([]pair, maxLog+1)
		stMin[i] = make([]pair, maxLog+1)
	}

	// 3. 填充st表的 base case (j=0)，即长度为 2^0 = 1 的区间
	for i := 0; i < n; i++ {
		stMax[i][0] = pair{val: nums[i], idx: i}
		stMin[i][0] = pair{val: nums[i], idx: i}
	}

	// 4. 使用动态规划填充整个st表
	for j := 1; j <= maxLog; j++ {
		for i := 0; i+(1<<j) <= n; i++ {
			// --- 处理最大值 ---
			p1Max := stMax[i][j-1]
			p2Max := stMax[i+(1<<(j-1))][j-1]
			// 如果值相等，我们优先选择下标较小的那个
			if p1Max.val >= p2Max.val {
				stMax[i][j] = p1Max
			} else {
				stMax[i][j] = p2Max
			}

			// --- 处理最小值 ---
			p1Min := stMin[i][j-1]
			p2Min := stMin[i+(1<<(j-1))][j-1]
			// 如果值相等，我们优先选择下标较小的那个
			if p1Min.val <= p2Min.val {
				stMin[i][j] = p1Min
			} else {
				stMin[i][j] = p2Min
			}
		}
	}

	return &SparseTable{
		logTable: logTable,
		stMax:    stMax,
		stMin:    stMin,
	}
}

// QueryMax 查询闭区间 [l, r] 内的最大值及其下标
func (st *SparseTable) QueryMax(l, r int) (val int, idx int) {
	length := r - l + 1
	k := st.logTable[length]

	p1 := st.stMax[l][k]
	p2 := st.stMax[r-(1<<k)+1][k]

	if p1.val >= p2.val {
		return p1.val, p1.idx
	}
	return p2.val, p2.idx
}

// QueryMin 查询闭区间 [l, r] 内的最小值及其下标
func (st *SparseTable) QueryMin(l, r int) (val int, idx int) {
	length := r - l + 1
	k := st.logTable[length]

	p1 := st.stMin[l][k]
	p2 := st.stMin[r-(1<<k)+1][k]

	if p1.val <= p2.val {
		return p1.val, p1.idx
	}
	return p2.val, p2.idx
}
