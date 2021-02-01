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

int d;



int prime[(int)1e7+500];
set<int> primes;

void solve() {
    cin >> d;

    int a = *primes.lower_bound(1+d);
    int b = *primes.lower_bound(a+d);

    cout << a*b << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 2; i < (int)1e7; i++) prime[i] = true;

    for(int i = 2; i <= 1e7; i++) {
        if(!prime[i]) continue;

        primes.emplace(i);

        for(int j = i*i; j <= 1e7; j += i) {
            prime[j] = false;
        }
    }

    // for(int x: primes) {
    //     cerr << x << " ";
    // }
    // cerr << endl;

    // cerr << primes[l-2] << " " << primes[l-1] << endl;
    int t;
    cin >> t;

    while(t--) solve();


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
