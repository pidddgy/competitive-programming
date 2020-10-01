// https://codeforces.com/contest/67/problem/D

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n'
#define int long long

const int maxn = 1000500;

int d[maxn];
vector<int> a[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;

        a[x].emplace_back(i);
    }

    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;

        a[x].emplace_back(i);
    }

    for(int i = 1; i <= n; i++) {
        sort(a[i].begin(), a[i].end());

        d[a[i][0]]++;
        d[a[i][1]+1]--;
    }

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        d[i] += d[i-1];
        ans = max(ans, d[i]);
    }

    cout << ans << endl;
}
