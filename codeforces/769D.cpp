// https://codeforces.com/contest/769/problem/D

#include <bits/stdc++.h>
using namespace std;
#define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n'
#define ld long double
#define int long long
#define pii pair<int, int>
#define fi first
#define ll long long
#define se second
#define sz(a) (int)a.size()
#define all(x) (x).begin(), (x).end()

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

void solve() {
    
}

const int maxn = 100500;
const int maxv = (int)1e4+50;
int n, k;
int a[maxn];

// masks w/ k set bits
vector<int> masks;

int cnt[maxv];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // cin >> n >> k;
    scan(n);
    scan(k);

    for(int i = 0; i <= 2e4; i++) {
        if(__builtin_popcountll(i) == k) {
            masks.emplace_back(i);
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        ll x;
        // cin >> x;
        scan(x);

        for(int m: masks) {
            if((ll)(x^m) <= (ll)1e4) {
                ans += cnt[x^m];
            }
        }

        cnt[x]++;
    }

    cout << ans << endl;
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