#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// for storing all bitwise and.
vector<int> v;
// Recursive function to print all
// possible subsequences for given array
void subsequence(int arr[], int index, vector<int>& subarr,
                int n, int k)
{
    // calculate the bitwise and when reach
    // at last index
    if (index == n) {
        if (subarr.size() == k) {
            int ans = subarr[0];
            for (auto it : subarr) {
                ans = ans & it;
            }
            v.push_back(ans); // storing the bitwise
            // and to vector v.
        }
        return;
    }
    else {
        // pick the current index into the subsequence.
        subarr.push_back(arr[index]);

        subsequence(arr, index + 1, subarr, n, k);

        subarr.pop_back();

        // not picking the element into the subsequence.
        subsequence(arr, index + 1, subarr, n, k);
    }
}

// Driver Code
int main()
{
    int arr[] = { 255, 127, 31, 5, 24, 37, 15 };
    int n = sizeof(arr) / sizeof(arr[0]);

    int k = 5;

    vector<int> vec;

    subsequence(arr, 0, vec, n, k);
    // maximum bitwise and is
    cout << *max_element(v.begin(), v.end());

    return 0;
}
