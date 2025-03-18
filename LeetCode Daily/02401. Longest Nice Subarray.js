var longestNiceSubarray = function (nums) {
    let n = nums.length;
    let maxLength = 1;
    let left = 0;
    let usedBits = 0;

    for (let right = 0; right < n; right++) {
        while ((usedBits & nums[right]) !== 0) {
            usedBits ^= nums[left];
            left++;
        }

        usedBits |= nums[right];
        maxLength = Math.max(maxLength, right - left + 1);
    }

    return maxLength;
};
