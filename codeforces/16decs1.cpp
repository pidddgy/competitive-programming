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

const int maxn = 100500;

int n, q;
int a[maxn];
pii quer[maxn];

int curc = 0;
vector<int> cmp;

map<int, int> ac;

int psa[5*maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("haybales.in", "r", stdin);
    freopen("haybales.out", "w", stdout);

    cin >> n >> q;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        cmp.emplace_back(a[i]);
    }

    for(int i = 1; i <= q; i++) {
        cin >> quer[i].fi >> quer[i].se;
        cmp.emplace_back(quer[i].fi);
        cmp.emplace_back(quer[i].se);
    }

    sort(all(cmp));

    for(int i = 0; i < sz(cmp); i++) {
        if(i == 0 or cmp[i] != cmp[i-1]) {
            ac[cmp[i]] = ++curc;
        }
    }

    for(int i = 1; i <= n; i++) {
        psa[ac[a[i]]]++;
    }

    for(int i = 1; i <= 4e5; i++) psa[i] += psa[i-1];

    for(int i = 1; i <= q; i ++) {
        cout << psa[ac[quer[i].se]]-psa[ac[quer[i].fi]-1] << endl;
    }
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
