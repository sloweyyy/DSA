var countDigitOne = function(n) {
    let count = 0;
    for (let factor = 1; factor <= n; factor *= 10) {
        const higher = Math.floor(n / (factor * 10));
        const digit = Math.floor(n / factor) % 10;
        const lower = n % factor;
        count += higher * factor;
        if (digit === 1) count += lower + 1;
        else if (digit > 1) count += factor;
    }
    return count;
};
