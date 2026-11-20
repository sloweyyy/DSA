class RandomizedCollection {
    private final List<Integer> values = new ArrayList<>();
    private final Map<Integer, Set<Integer>> positions = new HashMap<>();
    private final Random random = new Random();
    public RandomizedCollection() {
    }
    public boolean insert(int val) {
        Set<Integer> indices = positions.computeIfAbsent(val, key -> new LinkedHashSet<>());
        boolean first = indices.isEmpty();
        indices.add(values.size());
        values.add(val);
        return first;
    }
    public boolean remove(int val) {
        Set<Integer> indices = positions.get(val);
        if (indices == null) return false;
        int index = indices.iterator().next();
        indices.remove(index);
        int lastIndex = values.size() - 1;
        int lastValue = values.get(lastIndex);
        if (index != lastIndex) {
            values.set(index, lastValue);
            Set<Integer> lastIndices = positions.get(lastValue);
            lastIndices.remove(lastIndex);
            lastIndices.add(index);
        }
        values.remove(lastIndex);
        if (indices.isEmpty()) positions.remove(val);
        return true;
    }
    public int getRandom() {
        return values.get(random.nextInt(values.size()));
    }
}
