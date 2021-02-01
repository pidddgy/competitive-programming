// https://codeforces.com/contest/1220/problem/D

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
vector<int> a[80];
int b[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> b[i];
        int cpy = b[i];

        int facs = 0;
        while(b[i]%2==0) {
            b[i] /= 2;
            facs++;
        }

        cerr << "putting " << cpy << " in " << facs << endl;
        a[facs].emplace_back(cpy);
    }

    int best = 0;
    for(int i = 0; i <= 63; i++) {
        if(sz(a[i]) > sz(a[best])) {
            best = i;
        }
    }

    vector<int> ans;
    for(int i = 0; i <= 63; i++) {
        if(i != best) {
            for(int x: a[i]) {
                ans.emplace_back(x);
            }
        }
    }

    cout << sz(ans) << endl;
    for(int x: ans) {
        cout << x << " ";
    }
    cout << endl;
}

/*

no odd length cycles in bipartite graph

cycle length for any a, b in B is lcm(a, b)/a + lcm(a, b)/b

only case where both are even is if they share same power of 2

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
