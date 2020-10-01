// https://codeforces.com/contest/924/problem/C

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define cerr if(false) cerr
#define int long long

const int maxn = 100500;

// prefix max
int pma[maxn], a[maxn], marks[maxn];
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int ma = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        ma = max(ma, a[i]);
        pma[i] = ma;
    }

    for(int i = n; i >= 1; i--) {
        marks[i] = max(marks[i+1]-1, pma[i]+1);
    }

    for(int i = 1; i <= n; i++) {
        cerr << marks[i] << " ";
    }
    cerr << endl;

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        ans += marks[i]-a[i]-1;
    }
    cerr << endl;

    cout << ans << endl;

}