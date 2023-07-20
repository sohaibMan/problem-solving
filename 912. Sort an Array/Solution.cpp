/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

 void merge(int *arr, int const left, int mid, int const right) {

    // calculating the size of the left and right array
    int const leftArraySize = mid - left + 1;
    int const rightArraySize = right - mid;

    // reserving size for left and right arrays
    int *leftArray = malloc(sizeof(int)*leftArraySize);
    int *rightArray =  malloc(sizeof(int)*rightArraySize);

    // filling the arrays with the values from the nums array
    for (int i = 0; i < leftArraySize; i++)leftArray[i] = arr[left + i];
    for (int j = 0; j < rightArraySize; j++)rightArray[j] = arr[mid + 1 + j];

    int currentLeftIndex = 0, currentRightIndex = 0, currentMergedIndex = left;

    // while left and right have elements
    while (currentLeftIndex < leftArraySize && currentRightIndex < rightArraySize) {
        if (leftArray[currentLeftIndex] >= rightArray[currentRightIndex]) {
            arr[currentMergedIndex++] = rightArray[currentRightIndex++];
        } else {
            arr[currentMergedIndex++] = leftArray[currentLeftIndex++];
        }
    }
    // while there are elements in the left array
    while (currentLeftIndex < leftArraySize) {
        arr[currentMergedIndex++] = leftArray[currentLeftIndex++];
    }
    while (currentRightIndex < rightArraySize) {
        arr[currentMergedIndex++] = rightArray[currentRightIndex++];
    }
    free(leftArray);
    free(rightArray);
}

void mergeSort(int *nums, int left, int right) {
    if (left >= right)return;
    int mid = left + (right - left) / 2;
    mergeSort(nums, left, mid);
    mergeSort(nums, mid + 1, right);
    merge(nums, left, mid, right);
}

int* sortArray(int* nums, int numsSize, int* returnSize){
    *returnSize=numsSize;
    mergeSort(nums, 0, numsSize - 1);
    return nums;

}
