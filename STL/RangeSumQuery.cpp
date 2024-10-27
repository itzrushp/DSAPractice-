#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, Q;
    cin >> N >> Q;
    vector<int> arr(N);
    
    // Input array elements
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    // Creating the prefix sum array
    vector<int> prefix(N);
    prefix[0] = arr[0];
    for (int i = 1; i < N; i++) {
        prefix[i] = prefix[i - 1] + arr[i];
    }
    
    // Processing each query
    while (Q--) {
        int L, R;
        cin >> L >> R;
        if (L == 1) {
            cout << prefix[R - 1] << endl;
        } else {
            cout << prefix[R - 1] - prefix[L - 2] << endl;
        }
    }

    return 0;
}
