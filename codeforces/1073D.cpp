// https://codeforces.com/contest/1073/problem/D

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

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, T;
    cin >> n >> T;

    int mi = LLONG_MAX;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        mi = min(mi, a[i]);
    }

    int ans = 0;
    while(T >= mi) {
        int sum = 0, cnt = 0;

        int cpy = T;
        for(int i = 1; i <= n; i++) {
            if(T >= a[i]) {
                T -= a[i];
                sum += a[i];
                cnt++;
            }
        }

        ans += (cpy/sum) * cnt;
        T %= sum;
    }

    cout << ans << endl;
}

/*

iterate, use mod

on every operation T is roughly halved because the worst case is if we are barely under. otherwise we could do one entire iteration more

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
