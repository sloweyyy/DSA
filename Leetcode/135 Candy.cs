public class Solution
{
    public int Candy(int[] ratings)
    {
        var candies = new int[ratings.Length];
        for (var i = 0; i < candies.Length; i++)
        {
            candies[i] = 1;
        }

        for (var i = 1; i < candies.Length; i++)
        {
            if (ratings[i] > ratings[i - 1])
            {
                candies[i] = candies[i - 1] + 1;
            }
        }

        for (var i = candies.Length - 2; i >= 0; i--)
        {
            if (ratings[i] > ratings[i + 1])
            {
                candies[i] = Math.Max(candies[i], candies[i + 1] + 1);
            }
        }

        var sum = 0;
        foreach (var candy in candies)
        {
            sum += candy;
        }

        return sum;
    }
}