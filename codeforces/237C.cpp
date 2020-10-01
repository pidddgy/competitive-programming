// https://codeforces.com/contest/237/problem/C

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

const int maxv = (int)1e6+500;
bool prime[maxv];
int psa[maxv];
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 2; i <= 1e6; i++) prime[i] = true;

    for(int i = 2; i <= 1e6; i++) {
        if(prime[i]) {
            for(int j = i*i; j <= 1e6; j += i) prime[j] = false;
        }
    }

    for(int i = 1; i <= 1e6; i++) {
        psa[i] = psa[i-1] + prime[i];
    }

    int a, b, k;
    cin >> a >> b >> k;

    int lgood = -1;
    int l = 1, r = b-a+1;

    while(l <= r) {
        int mid = (l+r)/2;
        bool ok = true;

        for(int i = a; i <= b-mid+1; i++) {
            if(psa[i+mid-1] - psa[i-1] < k) ok = false;
        }

        if(ok) {
            lgood = mid;
            r = mid-1;
        } else {
            l = mid+1;
        }
    }

    cout << lgood << endl;
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
