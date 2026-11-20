int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    int counts[20001] = {
        0
    };
    int next[20001];
    for (int i = 0; i < numsSize; i++) counts[nums[i] + 10000]++;
    int* heads = malloc((numsSize + 1) * sizeof(int));
    for (int i = 0; i <= numsSize; i++) heads[i] = -1;
    for (int value = 0; value < 20001; value++) {
        if (counts[value] > 0) {
            next[value] = heads[counts[value]];
            heads[counts[value]] = value;
        }
    }
    int* result = malloc(k * sizeof(int));
    int count = 0;
    for (int frequency = numsSize; frequency > 0 && count < k; frequency--) {
        for (int value = heads[frequency]; value >= 0 && count < k; value = next[value]) result[count++] = value - 10000;
    }
    free(heads);
    *returnSize = k;
    return result;
}
