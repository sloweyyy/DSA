public class Solution
{
    public int MinDeletions(string s)
    {
        var charCount = new Dictionary<char, int>();
        foreach (var c in s)
        {
            if (!charCount.ContainsKey(c))
            {
                charCount.Add(c, 0);
            }
            charCount[c]++;
        }

        var charFrequencies = new HashSet<int>();
        var deletions = 0;
        for (var i = 0; i < charCount.Count; i++)
        {
            var count = charCount.ElementAt(i).Value;
            while (charFrequencies.Contains(count))
            {
                count--;
                deletions++;
            }
            if (count > 0)
            {
                charFrequencies.Add(count);
            }
        }

        return deletions;
    }
}
