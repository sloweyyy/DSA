function minCapability(nums: number[], k: number): number {
    // Binary search for the minimum capability
    let left = Math.min(...nums);
    let right = Math.max(...nums);

    while (left < right) {
        const mid = Math.floor((left + right) / 2);

        if (canRobEnoughHouses(nums, mid, k)) {
            // If we can rob enough houses with this capability,
            // try to find a smaller capability
            right = mid;
        } else {
            // Otherwise, we need a higher capability
            left = mid + 1;
        }
    }

    return left;
}

// Helper function to check if we can rob at least k houses
// with the given capability
function canRobEnoughHouses(
    nums: number[],
    capability: number,
    k: number
): boolean {
    let count = 0;
    let i = 0;

    while (i < nums.length) {
        // If the current house's value is within our capability
        if (nums[i] <= capability) {
            count++;
            i += 2; // Skip the next house (can't rob adjacent houses)
        } else {
            i++; // Skip this house and try the next one
        }
    }

    return count >= k;
}
