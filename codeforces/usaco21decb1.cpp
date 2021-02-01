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


    vector<int> v(7);
    for(int i = 0; i < 7; i++) {
        cin >> v[i];
    }

    sort(all(v));
    do {
        bool ok = true;
        int a = v[0], b = v[1], c = v[2];

        if((v[3] == a+b) and v[4] == b+c and v[5] == c+a and v[6] == a+b+c) {
            cout << v[0] << " " << v[1] << " " << v[2] << endl;
            return 0;
        }
    } while(next_permutation(all(v)));

    
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
