class Solution {
    fun countPrimes(n: Int): Int {
        if (n <= 2) return 0;
        val composite = BooleanArray(n);
        var prime = 2;
        while (prime * prime < n) {
            if (!composite[prime]) {
                var multiple = prime * prime;
                while (multiple < n) {
                    composite[multiple] = true;
                    multiple += prime;
                }
            };
            prime++;
        };
        var count = 0;
        for (value in 2 until n) {
            if (!composite[value]) count++;
        };
        return count;
    }
}
