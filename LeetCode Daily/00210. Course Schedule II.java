class Solution {
    public int[] findOrder(int numCourses, int[][] prerequisites) {
        List<List<Integer>> edges = new ArrayList<>();
        for (int i = 0; i < numCourses; i++) edges.add(new ArrayList<>());
        int[] indegree = new int[numCourses];
        for (int[] pair : prerequisites) {
            edges.get(pair[1]).add(pair[0]);
            indegree[pair[0]]++;
        }
        int[] order = new int[numCourses];
        int head = 0, tail = 0;
        for (int course = 0; course < numCourses; course++) if (indegree[course] == 0) order[tail++] = course;
        while (head < tail) {
            int course = order[head++];
            for (int next : edges.get(course)) if (--indegree[next] == 0) order[tail++] = next;
        }
        return tail == numCourses ? order : new int[0];
    }
}
