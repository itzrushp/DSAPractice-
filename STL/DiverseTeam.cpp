#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> arr;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        arr.push_back(a);
    }

    // Map to store the first occurrence index of each unique rating
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        if (mp.find(arr[i]) == mp.end()) {
            mp[arr[i]] = i;  // Store the first index where each unique rating appears
        }
    }

    // Check if we have enough unique ratings to form the team
    if (mp.size() < k) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        int count = 0;
        for (auto it = mp.begin(); it != mp.end() && count < k; ++it) {
            cout << it->second + 1 << " ";  // Output 1-based index
            count++;
        }
        cout << endl;
    }
    return 0;
}
