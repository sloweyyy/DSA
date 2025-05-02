func maxTaskAssign(tasks []int, workers []int, pills int, strength int) int {
	n := len(tasks)
	m := len(workers)

	// Sort both arrays
	sort.Ints(tasks)   // Sort tasks in ascending order (easier tasks first)
	sort.Ints(workers) // Sort workers in ascending order (weaker workers first)

	// Binary search for the maximum number of tasks
	left, right := 0, min(n, m)

	for left < right {
		mid := left + (right-left+1)/2 // Use ceiling midpoint

		if canAssign(mid, tasks, workers, pills, strength) {
			left = mid // Try to assign more tasks
		} else {
			right = mid - 1 // Can't assign this many tasks
		}
	}

	return left
}

// Helper function to check if we can assign k tasks
func canAssign(k int, tasks []int, workers []int, pills int, strength int) bool {
	if k == 0 {
		return true // We can always assign 0 tasks
	}

	m := len(workers) // Define m locally to avoid using the global variable

	// Take the k easiest tasks (from the beginning since tasks are sorted)
	easiestTasks := make([]int, k)
	copy(easiestTasks, tasks[:k])

	// Take the k strongest workers (from the end since workers are sorted)
	strongestWorkers := make([]int, k)
	for i := 0; i < k; i++ { // Fixed syntax error here - removed extra parenthesis
		strongestWorkers[i] = workers[m-k+i]
	}

	// Use a multiset (implemented with a slice) to track available workers
	availableWorkers := make([]int, k)
	copy(availableWorkers, strongestWorkers)
	sort.Ints(availableWorkers) // Sort in ascending order

	// Try to assign tasks starting from the hardest task
	for i := k - 1; i >= 0; i-- {
		task := easiestTasks[i]

		// If the strongest available worker can do this task without a pill
		if availableWorkers[len(availableWorkers)-1] >= task {
			// Use the strongest available worker
			availableWorkers = availableWorkers[:len(availableWorkers)-1]
		} else if pills > 0 {
			// Try to find a worker who can do this task with a pill
			foundWorker := false

			// Binary search to find the first worker who can complete the task with a pill
			left, right := 0, len(availableWorkers)-1
			for left <= right {
				mid := left + (right-left)/2
				if availableWorkers[mid]+strength >= task {
					right = mid - 1
				} else {
					left = mid + 1
				}
			}

			// If we found a worker who can do the task with a pill
			if left < len(availableWorkers) {
				availableWorkers = append(availableWorkers[:left], availableWorkers[left+1:]...)
				pills--
				foundWorker = true
			}

			if !foundWorker {
				return false // Can't assign this task
			}
		} else {
			return false // Can't assign this task and no pills left
		}
	}

	return true
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}