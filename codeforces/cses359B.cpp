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
 
void solve() {
    
}
 
const int maxn = 105;
 
int n;
int sum = 0;
int g[maxn];
 
void go(int group) {
    // look for sum+1
 
    watch(sum+group-2)
    int cur = 0;
    for(int i = n; i >= 1; i--) {
        if(!g[i] and cur+i <= sum+(group-2)) {
            cur += i;
            g[i] = group;
        }
    }
    
    assert(cur == sum+group-2);
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    cin >> n;
    
    sum = (n*(n+1))/2;
    
    watch(sum/3)
    if(sum % 3) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
 
    sum /= 3;
 
    go(1);
    go(2);
    go(3);
 
    for(int i = 1; i <= n; i++) {
        cout << g[i] << " ";
    }
    cout << endl;
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