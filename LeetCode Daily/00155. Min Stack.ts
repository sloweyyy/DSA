class MinStack {
    private entries: [number, number][] = [];
    constructor() {
    }
    push(val: number): void {
        const minimum = this.entries.length ? Math.min(val, this.getMin()) : val;
        this.entries.push([val, minimum]);
    }
    pop(): void {
        this.entries.pop();
    }
    top(): number {
        return this.entries[this.entries.length - 1][0];
    }
    getMin(): number {
        return this.entries[this.entries.length - 1][1];
    }
}
