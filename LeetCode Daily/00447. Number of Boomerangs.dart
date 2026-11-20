class Solution {
    int numberOfBoomerangs(List<List<int>> points) {
        int total = 0;
        for (int i = 0; i < points.length; i++) {
            final counts = <int, int> {
            };
            for (int j = 0; j < points.length; j++) {
                if (i == j) continue;
                int dx = points[i][0] - points[j][0], dy = points[i][1] - points[j][1];
                int distance = dx * dx + dy * dy;
                int previous = counts[distance] ?? 0;
                total += 2 * previous;
                counts[distance] = previous + 1;
            }
        }
        return total;
    }
}
