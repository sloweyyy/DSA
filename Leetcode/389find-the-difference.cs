public class Solution
{
    public char FindTheDifference(string s, string t)
    {
        int[] count = new int[26];
        foreach (char c in s)
        {
            count[c - 'a']++;
        }
        foreach (char c in t)
        {
            count[c - 'a']--;
        }
        for (int i = 0; i < 26; i++)
        {
            if (count[i] != 0)
            {
                return (char)('a' + i);
            }
        }
        return 'a';
    }
}