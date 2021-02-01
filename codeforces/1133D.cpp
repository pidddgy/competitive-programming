// https://codeforces.com/contest/1133/problem/D

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

int n;
int a[maxn];
int b[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cerr << fixed << setprecision(10);
    cout << fixed << setprecision(10);

    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for(int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    map<ld, int> cum;

    int shit = 0;
    for(int i = 1; i <= n; i++) {
        if(a[i] == 0) {
            if(b[i] == 0) shit++;
            continue;
        }

        ld need = (ld)((ld)(-b[i])/(ld)a[i]);

        cerr << i << " " << need << endl;


        cum[need]++;
    }

    int ans = 0;
    for(auto x: cum) {
        ans = max(ans, x.se);
    }

    cout << ans+shit << endl;
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
