const minZeroArray = (a, q) => {
    const n = a.length;
    const m = q.length;
    const diff = new Int32Array(n + 1);
    let k = 0;
    for (let i = 0, s = 0; i < n; ++i) {
        while (s + diff[i] < a[i]) {
            if (k === m) return -1;
            const [l, r, v] = q[k++];
            if (r < i) continue;
            diff[Math.max(l, i)] += v;
            diff[r + 1] -= v;
        }
        s += diff[i];
    }
    return k;
};
