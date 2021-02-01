// https://codeforces.com/contest/1407/problem/C

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

const int maxn = (int)1e4+600;

int n;
int ans[maxn];
bool used[maxn];

signed main() {
    cin >> n;

    int cur = 1;
    for(int i = 2; i <= n; i++) {
        cout << "? " << cur << " " << i << endl;
        int x;
        cin >> x;

        cout << "? " << i << " " << cur << endl;
        int y;
        cin >> y;

        if(x > y) {
            // cur = 
            ans[cur] = x;
            used[x] = true;
            cur = i;
        } else if(y > x) {
            ans[i] = y;
            used[y] = true;
        } else assert(false);
    }

    for(int i = 1; i <= n; i++) {
        if(!used[i]) {
            ans[cur] = i;
            break;
        }
    }

    cout << "! ";
    for(int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
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
