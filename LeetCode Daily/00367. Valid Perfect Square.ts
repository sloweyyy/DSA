function isPerfectSquare(num: number): boolean {
    let left = 1, right = Math.min(num, 46340);
    while (left <= right) {
        const middle = left + Math.floor((right - left) / 2);
        const square = middle * middle;
        if (square === num) return true;
        if (square < num) left = middle + 1;
        else right = middle - 1;
    }
    return false;
}
