// https://cses.fi/problemset/task/1092

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

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int sum = (n*(n+1))/2;

    if(sum&1) {
        cout << "NO" << endl;
        return 0;
    } else {
        sum /= 2; 
    }

    set<int> S, T;
    int x = 0;
    for(int i = n; i >= 1; i--) {
        if(x+i <= sum) {
            x += i;
            S.emplace(i);
        } else {
            T.emplace(i);
        }
    }

    cout << "YES" << endl;
    for(set<int> ree: vector<set<int>>{S, T}) {
        cout << sz(ree) << endl;
        for(int x: ree) {
            cout << x << " ";
        }
        cout << endl;
    }

    

    
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
