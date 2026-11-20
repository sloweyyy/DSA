func removeInvalidParentheses(s string) []string {
	leftRemove, rightRemove := 0, 0
	for i := 0; i < len(s); i++ {
		if s[i] == '(' {
			leftRemove++
		} else if s[i] == ')' {
			if leftRemove > 0 {
				leftRemove--
			} else {
				rightRemove++
			}
		}
	}
	unique := map[string]struct{}{}
	var visit func(int, int, int, int, []byte)
	visit = func(index, balance, left, right int, path []byte) {
		if len(s)-index < left+right {
			return
		}
		if index == len(s) {
			if balance == 0 && left == 0 && right == 0 {
				unique[string(path)] = struct{}{}
			}
			return
		}
		switch s[index] {
		case '(':
			if left > 0 {
				visit(index+1, balance, left-1, right, path)
			}
			visit(index+1, balance+1, left, right, append(path, s[index]))
		case ')':
			if right > 0 {
				visit(index+1, balance, left, right-1, path)
			}
			if balance > 0 {
				visit(index+1, balance-1, left, right, append(path, s[index]))
			}
		default:
			visit(index+1, balance, left, right, append(path, s[index]))
		}
	}
	visit(0, 0, leftRemove, rightRemove, make([]byte, 0, len(s)))
	result := []string{}
	for value := range unique {
		result = append(result, value)
	}
	return result
}
