// https://codeforces.com/contest/1385/problem/0

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n'
#define int long long
#define all(x) (x).begin(), (x).end()


void solve() {
    int x, y, z;
    cin >> x >> y >> z;
    
    vector<int> arr = {x, y, z, 1, 1, (int)1e9, (int)1e9};

    sort(arr.begin(), arr.end());

    do {
        int a = arr[0], b = arr[1], c = arr[2];

        if(x == max(a, b) and y == max(a, c) and z == max(b, c)) {
            cout << "YES" << endl;
            cout << a << " " << b << " " << c << endl;
            return;
        }
    } while(next_permutation(arr.begin(), arr.end()));

    cout << "NO" << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
    mt19937 mt(seed);

    int t;
    cin >> t;

    while(t--) {
        solve();
    }
}