// https://dmoj.ca/problem/heist

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

const int maxn = 30;

int v[maxn];

int n, k;

bool ok(int mask) {
    string s;
    for(int i = n-1; i >= 0; i--) {
        if(mask & (1LL << i)) {
            s += '1'; 
        } else {
            s += '0';
        }
    }

    // s += s;

    watch(s)

    int run = 0;
    for(char x: s) {
        if(x == '1') run++;
        else run = 0;

        if(run > k) return false;
    }

    int pre = 0;
    
    bool hugs = false;
    for(char x: s) {
        if(x == '1') pre++;
        else {
            hugs = true;
            break;
        }
    }

    if(hugs)
    if(pre+run > k) return false;

    return true;
}

void solve() {
    cin >> n >> k;

    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int ans = LLONG_MIN;
    for(int i = 0; i < (1<<n); i++) {
        if(ok(i)) {
            int loc = 0;
            for(int j = 0; j < n; j++) {
                if((1LL << j) & i) {
                    loc += v[j];
                }
            }

            ans = max(ans, loc);
        }
    }

    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);


    int t;
    cin >> t;

    while(t--) solve();
}

/*

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?