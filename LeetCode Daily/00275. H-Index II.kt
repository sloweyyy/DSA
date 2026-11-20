class Solution {
    fun hIndex(citations: IntArray): Int {
        var left = 0;
        var right = citations.size;
        while (left < right) {
            val middle = left + (right - left) / 2;
            if (citations[middle] >= citations.size - middle) right = middle else left = middle + 1;
        };
        return citations.size - left;
    }
}
