public class Solution
{
    public int IsWinner(int[] player1, int[] player2)
    {
        int[] scores = new int[2];
        for (int i = 0; i < player1.Length; i++)
        {
            if (player1[i] > player2[i])
            {
                scores[0]++;
            }
            else if (player1[i] < player2[i])
            {
                scores[1]++;
            }
        }
        if (scores[0] > scores[1])
        {
            return 1;
        }
        else if (scores[0] < scores[1])
        {
            return 2;
        }
        else
        {
            return 0;
        }
    }
}