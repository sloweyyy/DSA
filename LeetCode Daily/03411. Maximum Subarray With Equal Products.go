func maxLength(nums []int) int {
	gcd := func(a, b int) int {
		for b != 0 {
			a, b = b, a%b
		}
		return a
	}
	best := 0
	for i := range nums {
		product, g, l := 1, 0, 1
		for j := i; j < len(nums); j++ {
			x := nums[j]
			product *= x
			g = gcd(g, x)
			l = l / gcd(l, x) * x
			if product > 25200 {
				break
			}
			if product == g*l && j-i+1 > best {
				best = j - i + 1
			}
		}
	}
	return best
}
