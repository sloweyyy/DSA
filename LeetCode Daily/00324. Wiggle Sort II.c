void wiggleSort(int* nums, int numsSize) {
    int counts[5001] = {
        0
    };
    for (int i = 0; i < numsSize; i++) counts[nums[i]]++;
    int value = 5000;
    for (int parity = 1; parity >= 0; parity--) {
        for (int index = parity; index < numsSize; index += 2) {
            while (counts[value] == 0) value--;
            nums[index] = value;
            counts[value]--;
        }
    }
}
