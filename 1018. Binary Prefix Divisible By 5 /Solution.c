#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//
// Created by sohaib on 6/11/23.

//


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool *prefixesDivBy5(const int *nums, int numsSize, int *returnSize) {
    // 1 byte *
    *returnSize = (int) (sizeof(bool) * numsSize);
    bool *result = (bool *) malloc(*returnSize);
    int x = 0;
    // we know that If X is the first i digits of the array as a binary number, then 2X + A[i] is the first i+1 digits.
    for (int i = 0; i < numsSize; i++) {
        x = 2 * x + nums[i];
        if (x % 5 == 0){
            result[i] = true;
        }
        else result[i] = false;
        // to prevent x became to big
        if(x>=5)x-=5;

    }

    return result;
}


int main() {
    int A[] = {0, 1, 1, 1, 1, 1};
    int ASize = 6;
    int *returnSize = malloc(sizeof(int));
    bool *answer = prefixesDivBy5(A, ASize, returnSize);
    for (int i = 0; i < *returnSize; ++i) {
        printf("%d ", answer[i]);
    }

}