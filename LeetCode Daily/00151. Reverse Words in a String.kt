class Solution {
    fun reverseWords(s: String): String = s.split(' ').filter {
        it.isNotEmpty()
    }
    .asReversed().joinToString(" ");
}
