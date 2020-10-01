// https://codeforces.com/contest/621/problem/C

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

int l[maxn], r[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cout << fixed << setprecision(10);
    cerr << fixed << setprecision(10);

    int n, p;
    cin >> n >> p;

    for(int i = 0; i < n; i++) {
        cin >> l[i] >> r[i];
    }

    ld ans = 0;
    for(int i = 0; i < n; i++) {
        int j = (i+1)%n;

        // Multiples
        int mi = (r[i]/p) - ((l[i]-1)/p);
        int mj = (r[j]/p) - ((l[j]-1)/p);

        ld x = (ld)mi / (ld)(r[i]-l[i]+1);
        ld y = (ld)mj / (ld)(r[j]-l[j]+1);

        ld either = x+y - (x*y);

        cerr << mi << " " << mj << endl;
        cerr << x << " " << y << " -> " << either << endl;

        ans += 2000.0*either;
    }

    cout << ans << endl;
}

/*

each shark has x chance of being divisible (inclusion exclusion)

iterate over all pairs and calculate chance of neither being divisible
    let x = first shark probability of picking divisible number
    let y = second shark probability of picking divisible number

    p(either) = p(x) + p(y) - p(x and y)
*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
