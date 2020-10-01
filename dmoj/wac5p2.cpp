// https://dmoj.ca/problem/wac5p2

#include <bits/stdc++.h>
using namespace std;
// #define cerr if(false) cerr
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

int a[maxn];
int smi[maxn], sma[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, Q;
    cin >> N >> Q;

    for(int i = 1; i <= N; i++) {
        cin >> a[i];
    }

    smi[N] = sma[N] = a[N];

    for(int i = N-1; i >= 1; i--) {
        smi[i] = min(a[i], smi[i+1]);
        sma[i] = max(a[i], sma[i+1]);
    }

    while(Q--) {
        int L, e;
        cin >> L >> e;

        int l = 1;
        int r = N;
        int lgood = N+1;

        while(l <= r) {
            int m = (l+r)/2;

            if((abs(smi[m] - L) <= e) and (abs(sma[m] - L) <= e)) {
                lgood = m;
                r = m-1;
            } else {
                l = m+1;
            }
        }

        cout << N-lgood+1 << endl;
    }
}

/*

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
