class Solution {
    public List<List<Integer>> getSkyline(int[][] buildings) {
        List<int[]> events = new ArrayList<>();
        for (int[] building : buildings) {
            events.add(new int[] {
                building[0], -building[2]
            }
            );
            events.add(new int[] {
                building[1], building[2]
            }
            );
        }
        events.sort((a, b) -> Integer.compare(a[0], b[0]));
        TreeMap<Integer, Integer> heights = new TreeMap<>();
        heights.put(0, 1);
        List<List<Integer>> result = new ArrayList<>();
        int previous = 0, i = 0;
        while (i < events.size()) {
            int x = events.get(i)[0];
            while (i < events.size() && events.get(i)[0] == x) {
                int height = events.get(i)[1];
                if (height < 0) {
                    height = -height;
                    heights.put(height, heights.getOrDefault(height, 0) + 1);
                }
                else {
                    int count = heights.get(height);
                    if (count == 1) heights.remove(height);
                    else heights.put(height, count - 1);
                }
                i++;
            }
            int current = heights.lastKey();
            if (current != previous) {
                result.add(Arrays.asList(x, current));
                previous = current;
            }
        }
        return result;
    }
}
