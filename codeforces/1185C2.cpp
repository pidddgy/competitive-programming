// https://codeforces.com/contest/1185/problem/C2

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
int n, M;

int a[maxn], ans[maxn];
int cnt[200];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> M;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for(int i = 1; i <= n; i++) {
        cerr << "on " << i << endl;

        int rem = M-a[i];

        cerr << "have room for " << rem << endl;
        int keep = 0;
        for(int j = 1; j <= 100; j++) {
            assert(cnt[j] >= 0);

            int take = min(cnt[j], rem/j);
            keep += take;
            rem -= take*j;
        }

        watch(keep)
        // cout << n-1-take << " ";
        ans[i] = i-1-keep;
        cnt[a[i]]++;
    }

    for(int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

/*

maintain map of how many students have x cnt

loop over 1...100 and try to pick the entirety of x cnt

find how many students we can take with cnt x+1 with d i v i si io n 

wee math

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
