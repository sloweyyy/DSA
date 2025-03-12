function countOfSubstrings(word: string, k: number): number {
    // Two arrays: first marks which chars are vowels, second tracks their count
    const frequencies: number[][] = [
        new Array(128).fill(0),
        new Array(128).fill(0),
    ];

    // Mark all vowels in our lookup array
    "aeiou".split("").forEach((v) => (frequencies[0][v.charCodeAt(0)] = 1));

    let response = 0;
    let currentK = 0;
    let vowels = 0;
    let extraLeft = 0;
    let left = 0;

    // Sliding window approach
    for (let right = 0; right < word.length; right++) {
        const rightChar = word.charCodeAt(right);

        // Process current character
        if (frequencies[0][rightChar] === 1) {
            // It's a vowel - increment its count and check if it's a new unique vowel
            if (++frequencies[1][rightChar] === 1) vowels++;
        } else {
            // It's a consonant
            currentK++;
        }

        // Shrink window from left if we have too many consonants
        while (currentK > k) {
            const leftChar = word.charCodeAt(left);
            if (frequencies[0][leftChar] === 1) {
                // Removing a vowel
                if (--frequencies[1][leftChar] === 0) vowels--;
            } else {
                // Removing a consonant
                currentK--;
            }
            left++;
            extraLeft = 0;
        }

        // Handle duplicate vowels - can create additional valid substrings
        while (
            vowels === 5 &&
            currentK === k &&
            left < right &&
            frequencies[0][word.charCodeAt(left)] === 1 &&
            frequencies[1][word.charCodeAt(left)] > 1
        ) {
            extraLeft++;
            frequencies[1][word.charCodeAt(left)]--;
            left++;
        }

        // Count valid substrings when we have all 5 vowels and exactly k consonants
        if (currentK === k && vowels === 5) {
            response += 1 + extraLeft;
        }
    }

    return response;
}
re