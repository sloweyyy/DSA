typedef struct {
    int first;
    int second;
    long long sum;
}
PairEntry;
int** kSmallestPairs(int* nums1, int nums1Size, int* nums2, int nums2Size, int k, int* returnSize, int** returnColumnSizes) {
    int size = nums1Size < k ? nums1Size : k;
    PairEntry* heap = malloc(size * sizeof(PairEntry));
    for (int i = 0; i < size; i++) heap[i] = (PairEntry) {
        i, 0, (long long)nums1[i] + nums2[0]
    };
    int** result = malloc(k * sizeof(int*));
    *returnColumnSizes = malloc(k * sizeof(int));
    for (int count = 0; count < k; count++) {
        PairEntry entry = heap[0];
        result[count] = malloc(2 * sizeof(int));
        result[count][0] = nums1[entry.first];
        result[count][1] = nums2[entry.second];
        (*returnColumnSizes)[count] = 2;
        if (entry.second + 1 < nums2Size) {
            entry.second++;
            entry.sum = (long long)nums1[entry.first] + nums2[entry.second];
        }
        else {
            entry = heap[--size];
        }
        if (size > 0) {
            int index = 0;
            while (2 * index + 1 < size) {
                int child = 2 * index + 1;
                if (child + 1 < size && heap[child + 1].sum < heap[child].sum) child++;
                if (entry.sum <= heap[child].sum) break;
                heap[index] = heap[child];
                index = child;
            }
            heap[index] = entry;
        }
    }
    free(heap);
    *returnSize = k;
    return result;
}
