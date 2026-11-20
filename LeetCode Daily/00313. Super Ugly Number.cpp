class Solution {
    public: int nthSuperUglyNumber(int n, vector<int>& primes) {
        int count = primes.size();
        vector<long long> values(n, 1), candidates(primes.begin(), primes.end());
        vector<int> indices(count, 0);
        for (int i = 1; i < n; i++) {
            long long next = *min_element(candidates.begin(), candidates.end());
            values[i] = next;
            for (int j = 0; j < count; j++) {
                if (candidates[j] == next) {
                    indices[j]++;
                    candidates[j] = values[indices[j]] * primes[j];
                }
            }
        }
        return values[n - 1];
    }
};
