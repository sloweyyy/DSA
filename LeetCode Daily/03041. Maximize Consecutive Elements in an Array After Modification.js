/**
 * @param {number[]} nums
 * @return {number}
 */
var maxSelectedElements = function (nums) {
    nums.sort((a, b) => a - b);
    const dp = new Int32Array(nums[nums.length - 1] + 2);
    let answer = 0;

    for (const value of nums) {
        dp[value + 1] = Math.max(dp[value + 1], dp[value] + 1);
        dp[value] = Math.max(dp[value], dp[value - 1] + 1);
        answer = Math.max(answer, dp[value], dp[value + 1]);
    }

    return answer;
};
