class NumArray {
    constructor(nums) {
        this.values = nums.slice();
        this.tree = new Int32Array(nums.length + 1);
        for (let i = 1; i <= nums.length; i++) {
            this.tree[i] += nums[i - 1];
            const parent = i + (i & -i);
            if (parent <= nums.length) this.tree[parent] += this.tree[i];
        }
    }
    update(index, val) {
        const difference = val - this.values[index];
        this.values[index] = val;
        for (let i = index + 1; i < this.tree.length; i += i & -i) this.tree[i] += difference;
    }
    prefix(count) {
        let sum = 0;
        for (let i = count; i > 0; i -= i & -i) sum += this.tree[i];
        return sum;
    }
    sumRange(left, right) {
        return this.prefix(right + 1) - this.prefix(left);
    }
}
