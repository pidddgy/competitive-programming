// https://codeforces.com/contest/1359/problem/D

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define int long long

const int maxn = 100500;

int shift = 30;
// dp from left, right
int dpl[70][maxn];
int dpr[70][maxn];

// map<int, map<int, int>> dpl, dpr;
int a[maxn];


signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for(int i = -30; i <= 30; i++) {
        for(int j = 1; j <= n; j++) {
            int val = a[j];
            if(val > i) val = INT_MIN;

            dpl[i+shift][j] = max({val, val+dpl[i+shift][j-1], 0LL});
        }

        for(int j = n; j >= 1; j--) {
            int val = a[j];
            if(val > i) val = INT_MIN;

            dpr[i+shift][j] = max({val, val+dpr[i+shift][j+1], 0LL});
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        ans = max({ans, 0LL, dpl[a[i]+shift][i-1]+dpr[a[i]+shift][i+1]});
    }

    cout << ans << endl;
}
