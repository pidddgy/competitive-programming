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

const int maxn = 300500;

// in string 1 how far left can you go from i?
int l1[maxn], r1[maxn], l2[maxn], r2[maxn];
void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    string f1 = s;
    string f2 = s;

    for(int i = 0; i < sz(s); i++) {
        if(i % 2 == 0) {
            if(f1[i] == 'L') f1[i] = 'R';
            else f1[i] = 'L';
        } else {
            if(f2[i] == 'L') f2[i] = 'R';
            else f2[i] = 'L';
        }
    }

    // do l1
    int cur = 0;
    for(int i = 0; i <= n-1; i++) {
        l1[i] = cur;
        if(f1[i] == 'L') cur++;
        else cur = 0;
    }

    l1[n] = cur;

    // do l2
    cur = 0;
    for(int i = 0; i <= n-1; i++) {
        l2[i] = cur;
        if(f2[i] == 'L') cur++;
        else cur = 0;
    }

    l2[n] = cur;

    // do r1
    cur = 0;
    for(int i = n; i >= 1; i--) {
        r1[i] = cur;
        if(f1[i-1] == 'R') cur++;
        else cur = 0;
    }


    r1[0] = cur;

    watch(f1)   
    for(int i = 0; i <= n; i++) {
        cerr << r1[i] << " ";
    }
    cerr << endl;

    // do r2
    cur = 0;
    for(int i = n; i >= 1; i--) {
        r2[i] = cur;
        if(f2[i-1] == 'R') cur++;
        else cur = 0;
    }

    r2[0] = cur;

    for(int i = 0; i <= n; i++) {
        int ans = 0;
        if(i % 2 == 0) {
            // left
            if(i != 0) ans += l1[i];

            // right
            if(i != n) ans += r2[i];
        } else {
            // left
            if(i != 0) ans += l2[i];

            // right
            if(i != n) ans += r1[i];
        }

        cout << ans+1 << " ";
    }
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        solve();
    }
}

/*

road based on parity of time

if distance from src is even it will be flipped

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
