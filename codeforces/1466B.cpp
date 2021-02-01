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

const int maxn = 100500;

int n;
int a[maxn];

void solve() {
    cin >> n;

    multiset<int> S;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        S.emplace(a[i]);
    }   

    sort(a+1, a+n+1, greater<int>());

    for(int i = 1; i <= n; i++) {
        if(!S.count(a[i]+1)) {
            S.erase(S.find(a[i]));
            a[i]++;
            S.emplace(a[i]);
        }
    }

    set<int> ans;
    for(int x: S) ans.emplace(x);

    cout << sz(ans) << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    
    while(t--) solve();
}

/*

greedy

iterate over elements in nondecreasing order, shifting up as we go

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
