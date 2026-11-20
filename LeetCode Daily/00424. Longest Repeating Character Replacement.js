var characterReplacement = function(s, k) {
    const counts = Array(26).fill(0);
    let left = 0, most = 0, best = 0;
    for (let right = 0; right < s.length; right++) {
        most = Math.max(most, ++counts[s.charCodeAt(right) - 65]);
        while (right - left + 1 - most > k) counts[s.charCodeAt(left++) - 65]--;
        best = Math.max(best, right - left + 1);
    }
    return best;
};
