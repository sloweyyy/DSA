public class Solution
{
    public string ReverseWords(string s)
    {
        var words = s.Split(' ');
        for (var i = 0; i < words.Length; i++)
        {
            var word = words[i];
            var chars = word.ToCharArray();
            Array.Reverse(chars);
            words[i] = new string(chars);
        }

        return string.Join(" ", words);
    }
}