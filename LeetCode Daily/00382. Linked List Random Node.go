import "math/rand"

type Solution struct{ head *ListNode }

func Constructor(head *ListNode) Solution { return Solution{head: head} }
func (solution *Solution) GetRandom() int {
	chosen, count := 0, 0
	for node := solution.head; node != nil; node = node.Next {
		count++
		if rand.Intn(count) == 0 {
			chosen = node.Val
		}
	}
	return chosen
}
