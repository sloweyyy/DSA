/**
 Do not return anything, modify nums in-place instead.
 */
function sortColors(nums: number[]): void {
    const counts = [0, 0, 0];

    for (const num of nums) {
        counts[num]++;
    }

    let i = 0;
    for (let j = 0; j < 3; j++) {
        while (counts[j] > 0) {
            nums[i++] = j;
            counts[j]--;
        }
    }
}
