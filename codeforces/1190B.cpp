// https://codeforces.com/contest/1190/problem/B

#include <bits/stdc++.h>
using namespace std;
// #define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n'
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()

void no() {
    cout << "cslnb" << endl;
    exit(0);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int moves = 0;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(all(a));

    int changed = 0;
    for(int i = 0; i+1 < n; i++) {
        if(a[i] == a[i+1]) {
            if(!changed) {
                if((i >= 1) and (a[i]-1 == a[i-1])) no();
                if(a[i] == 0) no();
                a[i]--;
                changed = true;
                moves++;
            } else no();
        }
    }

    for(int i = 0; i < n; i++) {
        moves += a[i]-i;
    }

    if(moves&1) {
        cout << "sjfnb" << endl;
    } else {
        cout << "cslnb" << endl;
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