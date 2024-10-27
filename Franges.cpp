#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    // Read the array elements
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Initialize the difference array with size n+1
    vector<int> diff(n + 1, 0);

    // Process each query
    while (q--) {
        int L, R, val;
        cin >> L >> R >> val;
        L--; R--;
        diff[L] += val;      // Start adding val from index L-1
        
            diff[R+1] -= val;      // Stop adding val after index R-1
        
    }

    // Apply the difference array to the original array
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += diff[i];          // Accumulate the sum from the diff array
        arr[i] += sum;           // Update arr[i] with the accumulated sum
    }

    // Print the updated array
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
