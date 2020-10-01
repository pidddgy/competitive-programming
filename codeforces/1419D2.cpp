// https://codeforces.com/contest/1419/problem/D2

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

int a[maxn];
bool used[maxn];
int ans[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }    

    sort(a+1, a+n+1);

    int x = n/2;

    int ind = 1;
    for(int i = (n/2)+1; i <= n; i++) {
        // cout << a[i] << " ";
        ans[ind++] = a[i];
        if(!(n&1 and i == n)) {
            // cout << a[i-x] << " ";
            ans[ind++] = a[i-x];
        }
    }

    int ree = 0;
    for(int i = 2; i <= n-1; i++) {
        // cout << ans[i]
        if(ans[i] < ans[i-1] and ans[i] < ans[i+1]) {
            ree++;
        }

    }

    cout << ree << endl;

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
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
