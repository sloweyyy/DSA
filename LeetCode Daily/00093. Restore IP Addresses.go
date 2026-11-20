func restoreIpAddresses(s string) []string {
	result := []string{}
	valid := func(t string) bool {
		if len(t) == 0 || len(t) > 3 || (len(t) > 1 && t[0] == '0') {
			return false
		}
		n := 0
		for i := 0; i < len(t); i++ {
			n = n*10 + int(t[i]-'0')
		}
		return n <= 255
	}
	for a := 1; a <= 3 && a < len(s); a++ {
		for b := a + 1; b <= a+3 && b < len(s); b++ {
			for c := b + 1; c <= b+3 && c < len(s); c++ {
				if valid(s[:a]) && valid(s[a:b]) && valid(s[b:c]) && valid(s[c:]) {
					result = append(result, s[:a]+"."+s[a:b]+"."+s[b:c]+"."+s[c:])
				}
			}
		}
	}
	return result
}
