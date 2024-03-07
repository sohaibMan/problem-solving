#include <iostream>
#include <bits/stdc++.h>
#include <unordered_map>
#include <utility>
using namespace std;


// Function to be called when SIGALRM is sent to the process
void handle_alarm(int signal) {
    if (signal == SIGALRM) {
        std::cout << "Program terminated because it ran for more than 2 seconds." << std::endl;
        exit(0);
    }
}

int sum(const int l, const int r, const int prefixSum[], const int n) {
    return prefixSum[r - 1] - prefixSum[l - 1];
}

// Function that generate all valid
// triplets and calculate the value
// of the valid triplets
int max_valid_triplet(const int A[], const int n) {
    // Function to calculate the sum

    int ans = -1;
    int prefixSum[n];
    prefixSum[0] = A[0];
    for (int i = 1; i < n; i++) {
        prefixSum[i] = prefixSum[i - 1] + A[i];
    }


    // Generate all triplets
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            for (int k = j; k <= n + 1; k++) {
                // Check whether the triplet
                // is valid or not
                int grossValue = sum(1, i, prefixSum, n) -
                                 sum(i, j, prefixSum, n) +
                                 sum(j, k, prefixSum, n) -
                                 sum(k, n + 1, prefixSum, n);


                // Update the grossValue
                if (grossValue > ans) {
                    ans = grossValue;
                }
            }
        }
    }
    // cout << "sum(1, 2, A, n) " << sum(1, 2, A, n) << endl;
    return ans;
}


// Driver Code
int main() {
    int n = 3000;
    // Given array arr[]
    srand(time(0)); // Use current time as seed for random generator
    int arr[3000];

    for (int i = 0; i < 3000; i++) {
        arr[i] = rand() % 100; // Generate random numbers between 0 and 99
    }

    // Set up the function to be called when SIGALRM is sent to the process
    signal(SIGALRM, handle_alarm);

    // Schedule a SIGALRM signal to be sent after 2 seconds
    alarm(2);
    cout << "max_valid_triplet " << max_valid_triplet(arr, n) << endl;
    return 0;
}

// This code is contributed by chitranayal
