// https://dmoj.ca/problem/oly20practice121

#include <bits/stdc++.h>
using namespace std;
#define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n'
#define ld long double
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define sz(a) (int)a.size()
#define all(x) (x).begin(), (x).end()

void solve() {
    
}

const int maxn = 200500;

int n;
pii a[maxn];
int b[maxn];
int ans[maxn];

int pre[maxn]; 
int suf[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 1; i <= n+1; i++) {
        cin >> a[i].fi;
        a[i].se = i;
    }

    for(int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    sort(a+1, a+n+1+1);
    reverse(a+1, a+n+1+1);

    sort(b+1, b+n+1);
    reverse(b+1, b+n+1);

    for(int i = 1; i <= n; i++) {
        pre[i] = max(pre[i-1], (max(0LL, a[i].fi-b[i])));
    }

    for(int i = n; i >= 1; i--) {
        suf[i] = max(suf[i+1], max(0LL, a[i+1].fi-b[i]));
    }

    for(int i = 1; i <= n; i++) {
        cerr << pre[i] << " ";
    }
    cerr << endl;

    for(int i = 1; i <= n; i++) {
        cerr << suf[i] << " ";
    }
    cerr << endl;

    for(int i = 1; i <= n+1; i++) {
        int loc = max(pre[i-1], suf[i]);


        ans[a[i].se] = loc;
    }

    for(int i = 1; i <= n+1; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

/*

b[i] is with a[i] or a[i+1]

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
