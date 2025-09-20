// w464
func gcd(a int, b int) int {
	for b != 0 {
		t := b
		b = a % b
		a = t
	}
	return a
}

func gcdOfOddEvenSums(n int) int {
	sumOdd := 0
	sumEven := 0
	tempOdd := 1
	tempEven := 2
	for i := 0; i < n; i++ {
		sumOdd += tempOdd
		sumEven += tempEven
		tempOdd += 2
		tempEven += 2
	}
	return gcd(sumOdd, sumEven)
}