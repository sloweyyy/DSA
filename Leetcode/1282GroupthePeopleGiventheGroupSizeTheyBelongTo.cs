public class Solution
{
    public IList<IList<int>> GroupThePeople(int[] groupSizes)
    {
        var groups = new Dictionary<int, List<int>>();
        for (var i = 0; i < groupSizes.Length; i++)
        {
            if (!groups.ContainsKey(groupSizes[i]))
            {
                groups.Add(groupSizes[i], new List<int>());
            }
            groups[groupSizes[i]].Add(i);
        }

        var result = new List<IList<int>>();
        foreach (var group in groups)
        {
            var groupSize = group.Key;
            var groupMembers = group.Value;
            var groupCount = groupMembers.Count / groupSize;
            for (var i = 0; i < groupCount; i++)
            {
                var groupMembersSubset = groupMembers.GetRange(i * groupSize, groupSize);
                result.Add(groupMembersSubset);
            }
        }
        return result;
    }
}