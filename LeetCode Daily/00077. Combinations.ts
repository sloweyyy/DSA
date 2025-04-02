function combine(n: number, k: number): number[][] {
    const result: number[][] = [];
    const current: number[] = [];

    function backtrack(start: number) {
        if (current.length === k) {
            result.push([...current]);
            return;
        }

        for (let i = start; i <= n; i++) {
            current.push(i);
            backtrack(i + 1);
            current.pop();
        }
    }

    backtrack(1);

    return result;
}
