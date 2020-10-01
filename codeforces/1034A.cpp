// https://codeforces.com/contest/1034/problem/A

#include <bits/stdc++.h>
using namespace std;
#define cerr if(false) cerr
// #define cerr cout
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

const int maxn = 300500;
const int maxv = 15000500;

int n;
int a[maxn];
bool prime[maxv];
vector<int> primes;
int cnt[maxv];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }    

    int g = a[1];
    for(int i = 2; i <= n; i++) {
        g = __gcd(g, a[i]);
    }

    for(int i = 1; i <= n; i++) {
        a[i] /= g;
        cnt[a[i]]++;
        cerr << a[i] << " ";
    }
    cerr << endl;

    for(int i = 0; i < maxv; i++) {
        prime[i] = true;
    }

    prime[0] = prime[1] = false;

    int ma = 0;
    for(int i = 2; i <= 15000000; i++) {
        int d = 0;
        if(prime[i]) {
            primes.emplace_back(i);
            for(int j = i; j <= 15000000; j += i) {
                d += cnt[j];
                prime[j] = false;
            }
        }

        ma = max(ma, d);
    }

    if(ma == 0) {
        cout << -1 << endl;
    } else {
        cout << n-ma << endl;
    }
}

/*
1 161 895 003
*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
