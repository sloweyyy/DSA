public class Solution
{
    public bool WinnerOfGame(string colors)
    {
        var alice = 0;
        var bob = 0;
        for (var i = 1; i < colors.Length - 1; i++)
        {
            if (colors[i - 1] == colors[i] && colors[i] == colors[i + 1])
            {
                if (colors[i] == 'A')
                {
                    alice++;
                }
                else
                {
                    bob++;
                }
            }
        }

        return alice > bob;
    }
}