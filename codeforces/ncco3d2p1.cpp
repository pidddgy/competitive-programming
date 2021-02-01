// https://dmoj.ca/problem/ncco3d2p1

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

const int maxn = (int)5e4+200;

int a[maxn];
int segmi[maxn*3];
int segma[maxn*3];
int n, q;

void updmi(int ind, int val) {
    ind += n;

    segmi[ind] = val;

    for(int i = ind/2; i >= 1; i /= 2) {
        segmi[i] = min(segmi[i*2], segmi[i*2+1]);
    }
}

int querymi(int l, int r) {
    int ans = LLONG_MAX;
    l += n;
    r += n;

    while(l <= r) {
        if(l % 2 == 1) ans = min(ans, segmi[l++]);
        if(r % 2 == 0) ans = min(ans, segmi[r--]);

        l /= 2;
        r /= 2; 
    }

    return ans;
}

void updma(int ind, int val) {
    ind += n;

    segma[ind] = val;

    for(int i = ind/2; i >= 1; i /= 2) {
        segma[i] = max(segma[i*2], segma[i*2+1]);
    }
}

int queryma(int l, int r) {
    int ans = LLONG_MIN;
    l += n;
    r += n;

    while(l <= r) {
        if(l % 2 == 1) ans = max(ans, segma[l++]);
        if(r % 2 == 0) ans = max(ans, segma[r--]);

        l /= 2;
        r /= 2; 
    }

    return ans;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> q;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        updmi(i, a[i]);
        updma(i, a[i]);
    }

    while(q--) {
        int l, r;
        cin >> l >> r;

        cout << queryma(l, r)-querymi(l, r) << endl;
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
