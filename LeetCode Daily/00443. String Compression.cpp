class Solution {
    public: int compress(vector<char>& chars) {
        int write = 0;
        for (int i = 0; i < (int)chars.size();) {
            int j = i;
            while (j < (int)chars.size() && chars[j] == chars[i]) ++j;
            chars[write++] = chars[i];
            int count = j - i;
            if (count > 1) for (char digit : to_string(count)) chars[write++] = digit;
            i = j;
        }
        return write;
    }
};
