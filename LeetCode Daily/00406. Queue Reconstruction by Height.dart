class Solution {
    List<List<int>> reconstructQueue(List<List<int>> people) {
        people.sort((a, b) => a[0] == b[0] ? a[1].compareTo(b[1]) : b[0].compareTo(a[0]));
        final queue = <List<int>>[];
        for (final person in people) {
            queue.insert(person[1], person);
        }
        return queue;
    }
}
