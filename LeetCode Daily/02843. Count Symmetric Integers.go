func countSymmetricIntegers(low int, high int) int {
	count := 0
	for num := low; num <= high; num++ {
		if isSymmetric(num) {
			count++
		}
	}
	return count
}

func isSymmetric(num int) bool {
	// Convert number to string to check digits
	s := fmt.Sprintf("%d", num)
	n := len(s)

	// Numbers with odd number of digits are never symmetric
	if n%2 != 0 {
		return false
	}

	// Calculate sum of first half and second half
	half := n / 2
	sum1, sum2 := 0, 0

	for i := 0; i < half; i++ {
		sum1 += int(s[i] - '0')
		sum2 += int(s[half+i] - '0')
	}

	return sum1 == sum2
}
