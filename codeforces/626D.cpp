// https://codeforces.com/problemset/problem/626/D

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

const int maxn = 2005;
const int maxv = 5005;

int n;
int a[maxn], d[maxv], ssa[maxv];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for(int i = 1; i <= n; i++) {
        for(int j = i+1; j <= n; j++) {
            d[abs(a[i]-a[j])]++;
        }
    }

    for(int i = 4999; i >= 1; i--) {
        ssa[i] = ssa[i+1] + d[i];
    }

    ld cases = 0;
    for(int i = 1; i <= 5000; i++) {
        for(int j = 1; i+j+1 <= 5000; j++) {
            cases += d[i] * d[j] * ssa[i+j+1];
        }
    }

    ld total = ((n*(n-1))/2) * ((n*(n-1))/2) * ((n*(n-1))/2);

    watch(cases)
    watch(total)

    ld ans = cases/total;

    cout << fixed << setprecision(10) << ans << endl;
}

/*

out of all the cases where andrew wins game 1 and 2 and jerry wins 3, how many are there were jerry has a higher sum?

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
