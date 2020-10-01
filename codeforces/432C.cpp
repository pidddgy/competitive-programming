// https://codeforces.com/problemset/problem/432/C

#include <bits/stdc++.h>
using namespace std;
#define cerr if(false) cerr
// #define cerr cout
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n'
#define ld long double
// #define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define sz(a) (int)a.size()
#define all(x) (x).begin(), (x).end()

void solve() {
    
}

const int maxn = 100500;

int n;
int a[maxn];
int pos[maxn];

bool prime[maxn];
vector<int> primes;

vector<pii> ans;

void add(int i, int j) {
    if(i > j) swap(i, j);
    ans.emplace_back(i, j);
    swap(a[i], a[j]);
    swap(pos[a[i]], pos[a[j]]);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        pos[a[i]] = i;
    }

    for(int i = 0; i < maxn; i++) {
        prime[i] = true;
    }

    prime[0] = prime[1] = false;

    for(int i = 2; i*i <= 1e5+100; i++) {
        if(prime[i]) {
            for(int j = i*i; j <= 1e5+100; j += i) {
                prime[j] = false;
            }
        }
    }

    for(int i = 1; i <= 1e5+100; i++) {
        if(prime[i]) {
            cerr << i << " ";
            primes.emplace_back(i);
        }
    }
    cerr << endl;

    for(int i = 1; i <= n; i++) {
        cerr << "currently on " << i << endl;
        watch(pos[i]);
        while(pos[i] != i) {
            watch(pos[i]);
            int ind = lower_bound(primes.begin(), primes.end(), pos[i]-i+1) - primes.begin();
            cerr << "is initially " << primes[ind] << endl;
            while(primes[ind] > pos[i]-i+1) {
                ind--;
            }

            cerr << "using " << primes[ind] << endl;

            add(pos[i], pos[i]-primes[ind]+1);
            cerr << "is now " << pos[i] << endl;
        }
    }

    watch(sz(ans))
    assert(sz(ans) <= 5*n);

    cout << sz(ans) << endl;
    for(pii x: ans) {
        cout << x.fi << " " << x.se << endl;
    }
}

/*

uses goldbach conjecture

precompute primes

think about how to generate a "path" consisting of <= 3 prime numbers

if we need to swap 1 away, then use one swap to make the distance 3 then swap back after

in general

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
