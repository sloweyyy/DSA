import "sort"

func maxTaxiEarnings(n int, rides [][]int) int64 {
	if len(rides) == 0 {
		return 0
	}

	// sort rides by end time
	sort.Slice(rides, func(i, j int) bool { return rides[i][1] < rides[j][1] })

	m := len(rides)
	endTimes := make([]int, m)
	for i := 0; i < m; i++ {
		endTimes[i] = rides[i][1]
	}

	dp := make([]int64, m)
	for i := 0; i < m; i++ {
		start := rides[i][0]
		end := rides[i][1]
		tip := rides[i][2]
		earnings := int64(end - start + tip)

		// option 1: skip this ride
		if i > 0 {
			dp[i] = dp[i-1]
		} else {
			dp[i] = 0
		}

		// find rightmost ride that ends <= start among [0, i)
		idx := sort.Search(i, func(j int) bool { return endTimes[j] > start }) - 1

		var prev int64
		if idx >= 0 {
			prev = dp[idx]
		}
		if prev+earnings > dp[i] {
			dp[i] = prev + earnings
		}
	}

	return dp[m-1]
}