var reverseString = function(s) {
    for (let left = 0, right = s.length - 1; left < right; left++, right--) {
        const value = s[left];
        s[left] = s[right];
        s[right] = value;
    }
};
