class Solution {
    func wordBreak(_ s: String, _ wordDict: [String]) -> Bool {
        let characters = Array(s);
        let dictionary = Set(wordDict);
        let maximumLength = wordDict.map {
            $0.count
        }
        .max() ?? 0;
        var dp = Array(repeating: false, count: characters.count + 1);
        dp[0] = true;
        for end in 1...characters.count {
            for start in max(0, end - maximumLength)..<end {
                if dp[start] && dictionary.contains(String(characters[start..<end])) {
                    dp[end] = true;
                    break
                }
            }
        };
        return dp[characters.count]
    }
}
