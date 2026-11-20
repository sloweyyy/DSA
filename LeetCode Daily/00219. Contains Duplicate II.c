typedef struct {
    int value;
    int index;
}
ValueIndex;
int compareValueIndex(const void* first, const void* second) {
    const ValueIndex* a = first;
    const ValueIndex* b = second;
    if (a->value != b->value) return (a->value > b->value) - (a->value < b->value);
    return (a->index > b->index) - (a->index < b->index);
}
bool containsNearbyDuplicate(int* nums, int numsSize, int k) {
    if (k == 0) return false;
    ValueIndex* items = malloc(numsSize * sizeof(ValueIndex));
    for (int i = 0; i < numsSize; i++) {
        items[i].value = nums[i];
        items[i].index = i;
    }
    qsort(items, numsSize, sizeof(ValueIndex), compareValueIndex);
    for (int i = 1; i < numsSize; i++) {
        if (items[i].value == items[i - 1].value && items[i].index - items[i - 1].index <= k) {
            free(items);
            return true;
        }
    }
    free(items);
    return false;
}
