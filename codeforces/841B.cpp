// https://codeforces.com/contest/841/problem/B

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

const int maxn = (int)1e6+500;

int n;
int a[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    int sum = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    
    if(sum%2) {
        cout << "First" << endl;
    } else {
        // check if first can change parity
        bool f = false;
        for(int i = 1; i <= n; i++) {
            if(a[i]&1) f = true;
        }

        if(f) {
            cout << "First" << endl;
        } else {
            cout << "Second" << endl;
        }
    }
}

/*

odd -> player 1 wins

even -> 
    if no odd number player 2 wins
    otherwise it becomes odd

first person can always change parity how he wants it
*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
