object Solution {
    def countSegments(s: String): Int = {
        s.indices.count(i => s(i) != ' ' && (i == 0 || s(i - 1) == ' '))
    }
}
