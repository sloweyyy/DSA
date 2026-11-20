class Solution {
    fun canFinish(numCourses: Int, prerequisites: Array<IntArray>): Boolean {
        val edges = Array(numCourses) {
            mutableListOf<Int>()
        };
        val indegree = IntArray(numCourses);
        for (pair in prerequisites) {
            edges[pair[1]].add(pair[0]);
            indegree[pair[0]]++;
        };
        val queue = IntArray(numCourses);
        var head = 0;
        var tail = 0;
        for (course in 0 until numCourses) {
            if (indegree[course] == 0) queue[tail++] = course;
        };
        while (head < tail) {
            val course = queue[head++];
            for (next in edges[course]) {
                indegree[next]--;
                if (indegree[next] == 0) queue[tail++] = next;
            }
        };
        return head == numCourses;
    }
}
