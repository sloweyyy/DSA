public class Solution
{
    public int MinProcessingTime(IList<int> processorTime, IList<int> tasks)
    {
        int n = processorTime.Count;
        List<(int, int)> taskList = new List<(int, int)>();
        for (int i = 0; i < tasks.Count; i++)
        {
            taskList.Add((i, tasks[i]));
        }
        taskList.Sort((a, b) => b.Item2.CompareTo(a.Item2));
        List<int> processorTimeList = new List<int>(processorTime);
        processorTimeList.Sort((a, b) => b.CompareTo(a)); // sort processorTime in descending order
        int[] availableTime = new int[n];
        foreach ((int taskIndex, int taskTime) in taskList)
        {
            int processorIndex = Array.IndexOf(availableTime, availableTime.Min());
            availableTime[processorIndex] += taskTime * processorTimeList[processorIndex]; // multiply taskTime with processorTime
        }
        return availableTime.Max();
    }
}