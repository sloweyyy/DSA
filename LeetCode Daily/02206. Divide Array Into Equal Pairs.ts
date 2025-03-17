function divideArray(nums: number[]): boolean {
    const count = new Map<number, number>();
    for (const num of nums) {
        count.set(num, (count.get(num) || 0) + 1);
    }
    for (const [key, value] of count) {
        if (value % 2 !== 0) {
            return false;
        }
    }
    return true;
}
