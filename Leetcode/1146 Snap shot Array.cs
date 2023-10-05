using System.Collections.Generic;

public class SnapshotArray
{
    List<Dictionary<int, int>> snapshots;
    private int currentSnapId;
    
    public SnapshotArray(int length)
    {
        snapshots = new List<Dictionary<int, int>>();
        for (int i = 0; i < length; i++)
        {
            snapshots.Add(new Dictionary<int, int>());
        }
        currentSnapId = 0;
    }

    public void Set(int index, int val)
    {
        snapshots[index][currentSnapId] = val;
    }

    public int Snap()
    {
        currentSnapId++;
        return currentSnapId - 1;
    }

    public int Get(int index, int snap_id)
    {
        if (snapshots[index].ContainsKey(snap_id))
        {
            return snapshots[index][snap_id];
        }
        for (int i = snap_id - 1; i >= 0; i--)
        {
            if (snapshots[index].ContainsKey(i))
            {
                return snapshots[index][i];
            }
        }
        return 0;
    }
}

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray obj = new SnapshotArray(length);
 * obj.Set(index,val);
 * int param_2 = obj.Snap();
 * int param_3 = obj.Get(index,snap_id);
 */