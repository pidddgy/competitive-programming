// https://codeforces.com/contest/1264/problem/B

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

int acpy, bcpy, ccpy, dcpy;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<pii> pairs;
    for(int i = 0; i <= 3; i++) {
        for(int j = 0; j <= 3; j++) {
            pairs.emplace_back(i, j);
        }
    }

    cin >> acpy >> bcpy >> ccpy >> dcpy;

    do {
        int a = acpy, b = bcpy, c = ccpy, d = dcpy;

        vector<int> out;
        bool ok = true;
        for(int i = 1; i < sz(pairs); i++) {
            if(pairs[i].fi != pairs[i-1].se) ok = false;
        }

        if(!ok) continue;

        
    } while(next_permutation(all(pairs)));
}

/*

a sequence can be represented as a 2d array + starting integer

int a[4][4] where a[i][j] = number of times i, j appears as subarray of size 2

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
