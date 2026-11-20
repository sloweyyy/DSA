public class Solution {
    public int MaxProduct(string[] words) {
        int[] masks = new int[words.Length];
        for (int i = 0; i < words.Length; i++) foreach (char letter in words[i]) masks[i] |= 1 << (letter - 'a');
        int maximum = 0;
        for (int i = 0; i < words.Length; i++) for (int j = i + 1; j < words.Length; j++) if ((masks[i] & masks[j]) == 0) maximum = Math.Max(maximum, words[i].Length * words[j].Length);
        return maximum;
    }
}
