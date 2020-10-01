// https://codeforces.com/contest/898/problem/D

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define cerr if(false) cerr

const int maxn = 1000500;

int a[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    if(k == 1) {
        cout << n << endl;
        return 0;
    }
    set<int> S;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    
    }
    sort(a+1, a+n+1);

    int ans = 0;
    vector<int> arr;

    for(int i = 1; i <= n; i++) {
        int sz = (int)arr.size();
        if(sz < k-1 or i == 1) {
            arr.emplace_back(a[i]);
            continue;
        }

        if((a[i]-(arr[sz-(k-1)]))+1 <= m) {
            ans++;
        } else {
            arr.emplace_back(a[i]);
        }
    }

    cout << ans << endl;
}