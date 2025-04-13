func countGoodNumbers(n int64) int {
	// Constants
	const MOD = 1000000007

	// Count of even digits (0,2,4,6,8) = 5
	// Count of prime digits (2,3,5,7) = 4

	// For even positions we have 5 choices
	// For odd positions we have 4 choices

	// Calculate number of even and odd positions
	evenPos := (n + 1) / 2 // Ceiling division for even positions
	oddPos := n / 2        // Floor division for odd positions

	// Calculate result using fast power
	result := int64(1)

	// Helper function for fast modular exponentiation
	var modPow func(base, exp int64) int64
	modPow = func(base, exp int64) int64 {
		if exp == 0 {
			return 1
		}
		if exp == 1 {
			return base % MOD
		}
		half := modPow(base, exp/2)
		if exp%2 == 0 {
			return (half * half) % MOD
		}
		return (((half * half) % MOD) * base) % MOD
	}

	// Calculate 5^evenPos and 4^oddPos using fast power
	result = modPow(5, evenPos)
	if oddPos > 0 {
		result = (result * modPow(4, oddPos)) % MOD
	}

	return int(result)
}
