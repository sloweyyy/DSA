void selectMaximumDigits(int* nums, int size, int count, int* result) {
    int drop = size - count, top = 0;
    for (int i = 0; i < size; i++) {
        while (top > 0 && drop > 0 && result[top - 1] < nums[i]) {
            top--;
            drop--;
        }
        if (top < count) result[top++] = nums[i];
        else drop--;
    }
}
bool suffixGreater(int* first, int firstSize, int i, int* second, int secondSize, int j) {
    while (i < firstSize && j < secondSize && first[i] == second[j]) {
        i++;
        j++;
    }
    return j == secondSize || (i < firstSize && first[i] > second[j]);
}
int* maxNumber(int* nums1, int nums1Size, int* nums2, int nums2Size, int k, int* returnSize) {
    int* first = malloc(k * sizeof(int));
    int* second = malloc(k * sizeof(int));
    int* candidate = malloc(k * sizeof(int));
    int* best = malloc(k * sizeof(int));
    bool initialized = false;
    int minimum = k > nums2Size ? k - nums2Size : 0;
    int maximum = k < nums1Size ? k : nums1Size;
    for (int take = minimum; take <= maximum; take++) {
        selectMaximumDigits(nums1, nums1Size, take, first);
        selectMaximumDigits(nums2, nums2Size, k - take, second);
        int i = 0, j = 0;
        for (int position = 0; position < k; position++) {
            candidate[position] = suffixGreater(first, take, i, second, k - take, j) ? first[i++] : second[j++];
        }
        if (!initialized || suffixGreater(candidate, k, 0, best, k, 0)) {
            memcpy(best, candidate, k * sizeof(int));
            initialized = true;
        }
    }
    free(first);
    free(second);
    free(candidate);
    *returnSize = k;
    return best;
}
