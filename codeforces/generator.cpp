// Link

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
    mt19937 mt(seed);

    cout << 1 << endl;

    int n = (mt()%23)+1;
    int k = mt()%(n-3 + 1) + 3;

    cout << n << " " << k << endl;
}