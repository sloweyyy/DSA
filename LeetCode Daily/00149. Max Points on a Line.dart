class Solution {
    int maxPoints(List<List<int>> points) {
        int answer = 1;
        for (int i = 0; i < points.length; i++) {
            final counts = <String, int> {
            };
            for (int j = i + 1; j < points.length; j++) {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];
                final divisor = dx.gcd(dy);
                dx ~/= divisor;
                dy ~/= divisor;
                if (dx < 0 || (dx == 0 && dy < 0)) {
                    dx = -dx;
                    dy = -dy;
                }
                final key = "$dy/$dx";
                final count = (counts[key] ?? 0) + 1;
                counts[key] = count;
                if (count + 1 > answer) answer = count + 1;
            }
        }
        return answer;
    }
}
