// https://codeforces.com/contest/1176/problem/D

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

void solve() {
    
}

const int maxn = 200500;
const int maxv = 2750131+500;

int n;
int ind = 1;
int a[2*maxn], primes[2*maxn];
int spf[maxv];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i <= maxv; i++) spf[i] = i;
    
    for(int i = 2; i <= 2750131; i++) {
        if(spf[i] == i) {
            primes[ind++] = i;
            for(int j = i*i; j <= 2750131; j += i) {
                if(spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }

    cin >> n;

    multiset<int> prime, composite;
    for(int i = 1; i <= 2*n; i++) {
        cin >> a[i];

        if(spf[a[i]] == a[i]) {
            prime.emplace(a[i]);
        } else {
            composite.emplace(a[i]);
        }
    }    

    vector<int> ans;

    while(sz(composite)) {
        int in = *composite.rbegin();
        int out = in/spf[in];

        ans.emplace_back(in);

        composite.erase(composite.lower_bound(in));
        if(spf[out] == out) {
            // assert(prime.count(out));
            prime.erase(prime.lower_bound(out));
        } else {
            // assert(composite.count(out));
            composite.erase(composite.lower_bound(out));
        }
    }

    while(sz(prime)) {
        int in = *prime.begin();
        int out = primes[in];

        ans.emplace_back(in);

        prime.erase(prime.lower_bound(in));
        // assert(prime.count(out));
        prime.erase(prime.lower_bound(out));
    }

    assert(sz(ans) == n);
    for(int x: ans) {
        cout << x << " ";
    }
    cout << endl;
}

/*

partition half elements into those in a and those not in a

the biggest composite number must be in a, remove its corresponding pair
while we have composite numbers keep going

then go from smallest->biggest with primes




*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
