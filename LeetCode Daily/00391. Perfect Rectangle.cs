public class Solution {
    public bool IsRectangleCover(int[][] rectangles) {
        int left = int.MaxValue, bottom = int.MaxValue, right = int.MinValue, top = int.MinValue;
        long area = 0;
        var corners = new HashSet<(int X, int Y)>();
        void Toggle(int x, int y) {
            if (!corners.Add((x, y))) corners.Remove((x, y));
        }
        foreach (int[] rectangle in rectangles) {
            left = Math.Min(left, rectangle[0]);
            bottom = Math.Min(bottom, rectangle[1]);
            right = Math.Max(right, rectangle[2]);
            top = Math.Max(top, rectangle[3]);
            area += (long)(rectangle[2] - rectangle[0]) * (rectangle[3] - rectangle[1]);
            Toggle(rectangle[0], rectangle[1]);
            Toggle(rectangle[0], rectangle[3]);
            Toggle(rectangle[2], rectangle[1]);
            Toggle(rectangle[2], rectangle[3]);
        }
        return area == (long)(right - left) * (top - bottom) && corners.Count == 4 && corners.Contains((left, bottom)) && corners.Contains((left, top)) && corners.Contains((right, bottom)) && corners.Contains((right, top));
    }
}
