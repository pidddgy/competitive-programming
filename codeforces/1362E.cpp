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

int n, p;

const int MOD = (int)1e9+7;

int mod(int num) {
    return (num+MOD)%MOD;
}

int modpow(int a, int exp) {
    if(exp == 0) return 1;

    int t = modpow(a, exp / 2);
    if(exp % 2) return t*t % MOD * a%MOD;
    return t*t % MOD;
}

void solve() {
    cin >> n >> p;

    priority_queue<int> pq;

    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;

        pq.push(x);
    }

    if(p == 1) {
        cout << n%2 << endl;
        return;
    }

    while(sz(pq)) {
        int a = pq.top(); pq.pop();
        cerr << "taking " << a << endl;

        if(pq.empty()) {
            cout << modpow(p, a) << endl;
            return;
        }

        map<int, int> mp;

        int b = 0;
        while(sz(pq)) {
            int c = pq.top(); pq.pop();
            cerr << "taking " << c << endl;

            b += modpow(p, c);
            b = mod(b);

            mp[c]++;

            for(int i = c; i < a; i++) {
                if(mp[i] == p) {
                    mp[i+1]++;
                    mp[i] = 0;
                } else break;
            }

            if(mp[a] == 1) break;

            if(pq.empty()) {
                cout << mod(modpow(p, a)-b) << endl;
                return;
            }
        }

        if(pq.empty()) {
            cout << 0 << endl;
            return;
        }
    }

    cout << 0 << endl;
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