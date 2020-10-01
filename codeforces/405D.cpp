// https://codeforces.com/contest/405/problem/D

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

const int maxv = 1e6;
bool a[maxv+500];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;

        a[x] = true;
    }

    int pairs = 0;
    vector<int> ans;

    for(int i = 1; i <= 1e6; i++) {
        if(i <= 10) {
            cerr << "inv of " << i << " is " << maxv-i+1 << endl;
        }
        if(a[i] and a[maxv-i+1]) {
            pairs++;
        } else if(a[i]) {
            ans.emplace_back(maxv-i+1);
        }   
    }

    watch(pairs)
    pairs /= 2;

    for(int i = 1; i <= 1e6 and pairs; i++) {
        if(!a[i] and !a[maxv-i+1]) {
            ans.emplace_back(i);
            ans.emplace_back(maxv-i+1);
            pairs--;
        }
    }

    cout << sz(ans) << endl;
    for(int x: ans) {
        cout << x << " ";
    }
    cout << endl;

    for(int x: ans) {
        cerr << x << " contributes " << (1e6-x) << endl;
    }
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
