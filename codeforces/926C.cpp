// https://codeforces.com/contest/926/problem/C

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

void no() {
    cout << "NO" << endl;
    exit(0);
}

const int maxn = 100050;

int a[maxn];
int psa[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];        
    }

    int len = n;
    for(int i = 1; i <= n; i++) {
        if(a[i] != a[1]) {
            len = i-1;
            break;
        }
    }    

    for(int i = 1; i <= n; i++) {
        psa[i] = psa[i-1] + a[i];
    }

    if(n%len) no();

    for(int i = len; i <= n; i += len) {
        int sum = psa[i]-psa[i-len];

        if(sum and sum!=len) {
            no();
        }

        if(i >= len*2) {
            if(sum == psa[i-len]-psa[i-2*len]) {
                no();
            }
        }
    }

    cout << "YES" << endl;
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
