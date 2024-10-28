#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, q;
    cin >> n >> m >> q;

    // Read the array elements
    vector<vector<int>> arr(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    // Compute the prefix sum array with 1-based indexing
    vector<vector<int>> prefixSum(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            prefixSum[i][j] = arr[i - 1][j - 1]
                            + prefixSum[i - 1][j]
                            + prefixSum[i][j - 1]
                            - prefixSum[i - 1][j - 1];
        }
    }

    // Process each query
    while (q--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        // Calculate the sum for the rectangle defined by (x1, y1) to (x2, y2)
        int sum = prefixSum[x2][y2]
                - prefixSum[x1 - 1][y2]
                - prefixSum[x2][y1 - 1]
                + prefixSum[x1 - 1][y1 - 1];
        
        cout << sum << endl;
    }
    return 0;
}
