function moveZeroes(nums: number[]): void {
    let write = 0;
    for (let read = 0; read < nums.length; read++) {
        if (nums[read] !== 0) {
            if (write !== read) nums[write] = nums[read];
            write++;
        }
    }
    while (write < nums.length) {
        if (nums[write] !== 0) nums[write] = 0;
        write++;
    }
}
