/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func deleteDuplicates(head *ListNode) *ListNode {
    dummy := &ListNode{Val: 0, Next: head}
    current := dummy

    for current != nil && current.Next != nil {
        if current.Next.Next != nil && current.Next.Val == current.Next.Next.Val {
            val := current.Next.Val
            for current.Next != nil && current.Next.Val == val {
                current.Next = current.Next.Next
            }
        } else {
            current = current.Next
        }
    }

    return dummy.Next
}
