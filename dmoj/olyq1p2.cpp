// https://dmoj.ca/problem/olyq1p2

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n'
#define cerr if(false) cerr
#define ld long double
// #define int long long

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;



#define pii pair<int, int>
#define fi first
#define se second
#define sz(a) (int)a.size()
#define all(x) (x).begin(), (x).end()

void solve() {
    
}

const int maxn = (int)2e6+5;
int a[maxn];

int dp[maxn][2];
int n;

int roseseg[maxn*4];
int fellseg[maxn*4];

vector<int> cmp;

void upd(int k, int v, int *arr) {
    k += sz(cmp);
    arr[k] = v;
    for (int i = k/2; i != 0; i /= 2) {
        arr[i] = max(arr[i*2], arr[i*2+1]);
    }
}

int query(int l, int r, int *arr) {
    l += sz(cmp); r += sz(cmp);
    int res = 0;
    while (l <= r) {
        if(l&1) res = max(res, arr[l++]);
        if(r % 2 == 0) res = max(res, arr[r--]);
        
        l /= 2;
        r /= 2;
    }
    return res;
}

set<int> S;

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        cmp.emplace_back(a[i]);
    }

    sort(all(cmp));
    cmp.erase(unique(all(cmp)), cmp.end());
    for(int i = 1; i <= n; i++) {
        a[i] = lower_bound(all(cmp), a[i]) - cmp.begin();
    }

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        dp[i][0] = dp[i][1] = 1;
        dp[i][0] = max(dp[i][0], query(a[i]+1, sz(cmp), roseseg)+1);
        dp[i][1] = max(dp[i][1], query(0, a[i]-1, fellseg)+1);
        
        ans = max({ans, dp[i][0], dp[i][1]});

        upd(a[i], dp[i][0], fellseg);
        upd(a[i], dp[i][1], roseseg);
    }

    cout << ans << endl;
}

/*


dp[n][2] = biggest subseq ending on this element if we just rose or fell
1 = just rose, 0 = just fell

set<pii> for just rose or just fell

.fi = element, .se = length

binary search for max length possible

segment arr stores "if we use x element, what is the biggest length we can get"

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga arr)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?