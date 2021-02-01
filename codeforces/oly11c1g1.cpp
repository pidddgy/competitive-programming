// https://dmoj.ca/problem/oly11c1g1

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

const int maxn = 100500;

int a[maxn];
int psa[maxn];

int shift = 1e5+20;

int bit[4*maxn];

void upd(int ind, int val) {
    for(int i = ind; i <= 3*maxn; i += i &-i) {
        bit[i] += val;
    }
}

int sum(int ind) {
    int res = 0;
    for(int i = ind; i >= 1; i -= i & -i) {
        res += bit[i];
    }
    return res;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, l;
    cin >> n >> l;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        if(a[i] >= l) psa[i]++;
        else psa[i]--;

        psa[i] += psa[i-1];
    }

    int ans = 0;
    upd(shift, 1);
    int tot = 0;
    for(int i = 1; i <= n; i++) {
        int x = psa[i];
        ans += sum(x+shift);
        watch(x)
        cerr << "adding beginning to " << x-1 << endl;
        watch(sum(x+shift))

        cerr << "updating " << psa[i] << endl;
        upd(psa[i]+shift, 1);
        tot++;
        cerr << endl;
    }

    cout << ans << endl;
}

/*

count positive subarrays

if we have x we can remove up to x-1
*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
