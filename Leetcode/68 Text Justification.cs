public class Solution
{
    public IList<string> FullJustify(string[] words, int maxWidth)
    {
        IList<string> result = new List<string>();
        int i = 0;
        while (i < words.Length)
        {
            int j = i + 1;
            int lineLength = words[i].Length;
            while (j < words.Length && lineLength + words[j].Length + 1 <= maxWidth)
            {
                lineLength += words[j].Length + 1;
                j++;
            }
            int spaceCount = maxWidth - lineLength;
            int spaceBetweenWords = 1;
            int extraSpace = 0;
            if (j != i + 1 && j != words.Length)
            {
                spaceBetweenWords = spaceCount / (j - i - 1) + 1;
                extraSpace = spaceCount % (j - i - 1);
            }
            StringBuilder sb = new StringBuilder();
            sb.Append(words[i]);
            for (int k = i + 1; k < j; k++)
            {
                for (int l = 0; l < spaceBetweenWords; l++)
                {
                    sb.Append(" ");
                }
                if (extraSpace > 0)
                {
                    sb.Append(" ");
                    extraSpace--;
                }
                sb.Append(words[k]);
            }
            while (sb.Length < maxWidth)
            {
                sb.Append(" ");
            }
            result.Add(sb.ToString());
            i = j;
        }
        return result;
    }
}