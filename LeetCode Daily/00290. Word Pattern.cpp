class Solution {
    public: bool wordPattern(string pattern, string s) {
        unordered_map<char, int> letters;
        unordered_map<string, int> words;
        istringstream input(s);
        string word;
        for (int i = 0; i < pattern.size(); i++) {
            if (!(input >> word) || letters[pattern[i]] != words[word]) return false;
            letters[pattern[i]] = i + 1;
            words[word] = i + 1;
        }
        return !(input >> word);
    }
};
