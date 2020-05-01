// https://codeforces.com/contest/1330/problem/B

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define pii pair<int, int>
#define fi first
#define se second
#define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;

const int maxn = 200500;

int a[maxn];
int used[maxn];
int used2[maxn];
int used3[maxn];
int used4[maxn];


bool good(int l, int r, int arr[]) {
    int n = (r-l)+1;

    for(int i = l; i <= r; i++) {
        arr[a[i]] = true;
    }

    for(int i = 1; i <= n; i++) {
        if(!arr[i]) {
            return false;
        }
    }

    return true;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        for(int i = 0; i < n+5; i++) {
            used[i] = false;
            used2[i] = false;
            used3[i] = false;
            used4[i] = false;
        }

        int ma = 0;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
            ma = max(ma, a[i]);
        }

        set<pii> ans;
        if(good(1, ma, used) and good(ma+1, n, used2)) {
            ans.emplace(ma, n-ma);
        }

        if(good(1, n-ma, used3) and good(n-ma+1, n, used4)) {
            ans.emplace(n-ma, ma);
        }

        cout << ans.size() << endl;
        for(pii x: ans) {
            cout << x.fi << " " << x.se << endl;
        }
    }
}