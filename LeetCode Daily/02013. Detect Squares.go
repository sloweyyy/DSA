func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

type DetectSquares struct {
	points map[[2]int]int
}

func Constructor() DetectSquares {
	return DetectSquares{points: make(map[[2]int]int)}
}

func (this *DetectSquares) Add(point []int)  {
	this.points[[2]int{point[0], point[1]}]++
}

func (this *DetectSquares) Count(point []int) int {
	x, y := point[0], point[1]
	ans := 0
	
	for p, count1 := range this.points {
		px, py := p[0], p[1]
		// Check if current point can form a square with the query point
		if abs(px-x) > 0 && abs(px-x) == abs(py-y) {
			// Get counts of the other two points needed to form a square
			count2 := this.points[[2]int{x, py}]
			count3 := this.points[[2]int{px, y}]
			ans += count1 * count2 * count3
		}
	}
	
	return ans
}

/**
 * Your DetectSquares object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Add(point);
 * param_2 := obj.Count(point);
 */
