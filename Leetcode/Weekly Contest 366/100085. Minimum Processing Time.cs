

public class Solution
{
    public int MinProcessingTime(int[] processorTime, int[] tasks)
    {
        int n = processorTime.Length;
        int m = tasks.Length;

        Array.Sort(processorTime, (a, b) => b - a); // Sort processors in descending order.

        long left = 0;
        long right = (long)processorTime[0] * m; // Maximum possible time

        while (left < right)
        {
            long mid = left + (right - left) / 2;

            if (IsFeasible(processorTime, tasks, mid))
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }

        return (int)left;
    }

    private bool IsFeasible(int[] processorTime, int[] tasks, long maxTime)
    {
        int n = processorTime.Length;
        int m = tasks.Length;
        int taskIndex = m - 1;

        for (int i = 0; i < n; i++)
        {
            long timeLeft = maxTime / processorTime[i];

            while (taskIndex >= 0 && tasks[taskIndex] <= timeLeft)
            {
                timeLeft -= tasks[taskIndex];
                taskIndex--;
            }
        }

        return taskIndex < 0;
    }
}
