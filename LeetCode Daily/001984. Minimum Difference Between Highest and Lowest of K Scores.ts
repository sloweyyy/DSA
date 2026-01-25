function minimumDifference(nums: number[], k: number): number {
  // Sort the array
  nums.sort((a, b) => a - b);
  
  // Initialize the minimum difference to a large value
  let minDiff = Infinity;
  
  // Iterate through the array and find the minimum difference
  for (let i = 0; i <= nums.length - k; i++) {
    const diff = nums[i + k - 1] - nums[i];
    minDiff = Math.min(minDiff, diff);
  }
  
  return minDiff;
};