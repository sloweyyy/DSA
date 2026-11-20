var countRangeSum = function(nums, lower, upper) {
    const prefix = new Float64Array(nums.length + 1);
    const buffer = new Float64Array(prefix.length);
    for (let i = 0; i < nums.length; i++) prefix[i + 1] = prefix[i] + nums[i];
    function sort(left, right) {
        if (right - left <= 1) return 0;
        const middle = Math.floor((left + right) / 2);
        let count = sort(left, middle) + sort(middle, right);
        let start = middle, end = middle;
        for (let i = left; i < middle; i++) {
            while (start < right && prefix[start] - prefix[i] < lower) start++;
            while (end < right && prefix[end] - prefix[i] <= upper) end++;
            count += end - start;
        }
        let i = left, j = middle, position = left;
        while (i < middle && j < right) buffer[position++] = prefix[i] <= prefix[j] ? prefix[i++] : prefix[j++];
        while (i < middle) buffer[position++] = prefix[i++];
        while (j < right) buffer[position++] = prefix[j++];
        for (let index = left; index < right; index++) prefix[index] = buffer[index];
        return count;
    }
    return sort(0, prefix.length);
};
