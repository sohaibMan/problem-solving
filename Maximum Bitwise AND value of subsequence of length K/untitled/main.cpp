#include <bits/stdc++.h>
using namespace std;

// Function to find the maximum sum of
// a subsequence whose Bitwise AND is non-zero
int getMaxLengh(int const arr_count, const int* arr) {
    // Stores the resultant maximum
    // sum of the subsequence
    int ans = 0;

    // Iterate over all the bits
    for (int bit = 0; bit < 32; bit++) {
        // Stores the sum of array
        // elements whose i-th bit is set
        int sum = 0;

        // Traverse the array elements
        for (int i = 0; i < arr_count; i++) {
            // If the bit is set, then
            // add its value to the sum
            if (arr[i] & (1 << bit)) {
                sum += 1;
            }
        }

        // Update the resultant
        // maximum sum
        ans = max(ans, sum);
    }

    // Return the maximum sum
    return ans;
}

// Driver Code
int main() {
    int arr[] = {7, 4, 11, 8, 3};
    int N = sizeof(arr) / sizeof(arr[0]);
    cout << getMaxLengh(N, arr);
    // -----
    int arr1[] = {1, 2, 4, 8};
    cout << getMaxLengh(4, arr1);
    return 0;
}
