#include <bits/stdc++.h>
using namespace std;
// #define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n'
#define ld long double
// #define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define sz(a) (int)a.size()
#define all(x) (x).begin(), (x).end()

void solve() {
    
}

const int maxn = 100500;

int n;
int a[maxn];


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    stack<int> S;
    vector<pii> ans;
    int cur = 0;
    for(int i = 1; i <= n; i++) {
        if(cur < a[i]) {
            for(int j = 1; j <= a[i]-cur; j++) {
                S.push(i);
            }
        } else if(cur > a[i]) {
            for(int j = 1; j <= cur-a[i]; j++) {
                ans.emplace_back(S.top(), i-1);
                S.pop();
            }
        }
        cur = a[i];
    }

    while(sz(S)) {
        ans.emplace_back(S.top(), n);
        S.pop();
    }

    cout << sz(ans) << endl;
    for(pii x: ans) {
        cout << x.fi << " " << x.se << endl;
    }
}

/*

on each recursive call knock out the min element

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
