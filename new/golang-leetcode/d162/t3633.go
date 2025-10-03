// 双周赛162
func earliestFinishTime(landStartTime []int, landDuration []int, waterStartTime []int, waterDuration []int) int {
	ans := math.MaxInt
	end := math.MaxInt
	for i, x := range landStartTime {
		end = min(end, x+landDuration[i])
	}

	for i, x := range waterStartTime {
		ans = min(ans, max(x, end)+waterDuration[i])
	}

	end = math.MaxInt
	for i, x := range waterStartTime {
		end = min(end, x+waterDuration[i])
	}

	for i, x := range landStartTime {
		ans = min(ans, max(x, end)+landDuration[i])
	}
	return ans
}