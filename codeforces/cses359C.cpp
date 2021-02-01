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
#define sz(a) (int)(a).size()
#define y1 lsdjkfhshfdsighoihweogihewoghi
#define all(x) (x).begin(), (x).end()
 
 
const int maxn = 105;
 
int a[maxn];
 
void solve() {
    int n;    
    cin >> n;

    for(int i = 1; i <= n; i++) cin >> a[i];

    int inv = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = i+1; j <= n; j++) {
            if(a[i] > a[j]) {
                inv++;
            }
        }
    }

    if((inv)%2 == 0 and ) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}
 
 
 
 
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int t;
    cin >> t;
 
    while(t--) solve();
}
 
/*
 
simulate
 
*/
 
// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?