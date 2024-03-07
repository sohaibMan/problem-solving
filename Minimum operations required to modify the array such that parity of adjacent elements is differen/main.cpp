// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;


// Function to return the minimum
// number of operations required
#include <cmath> // for floor function


int solve(int* array, const int size) {
    int operations = 0;
    int i = 0;

    while (i < size - 1) {
        while (array[i] % 2 == array[i + 1] % 2) {
            operations++;
            array[i + 1] = floor(array[i + 1] / 2);
        }
        i++;
    }

    return operations;
}

// Driver Code
int main() {
    int array[] = {4, 10, 10, 6, 3}; //3
    int size = sizeof(array) / sizeof(array[0]);z
    cout << solve(array, size) << endl;

    int array2[] = {6, 5, 9, 7, 3}; //3
    int size2 = sizeof(array2) / sizeof(array2[0]);
    cout << solve(array2, size2) << endl;

    // int array3[] = {2, 1, 4, 7, 2}; //0
    // int size3 = sizeof(array3) / sizeof(array3[0]);
    // cout << solve(array3, size3) << endl;

    return 0;
}
