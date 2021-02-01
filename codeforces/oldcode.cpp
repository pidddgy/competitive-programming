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
#define sz(a) (int)(a).size()
#define y1 lsdjkfhshfdsighoihweogihewoghi
#define all(x) (x).begin(), (x).end()
 
const int maxn = 10;
int n;
set<vector<int>> vis;

map<vector<int>, vector<int>> par;
 
void solve() {
    vis.clear();
    cin >> n;
 
    vector<int> a;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
 
        a.push_back(x);
    }    

    vector<int> orig = a;
 
    queue<vector<int>> Q;
    Q.push(a);
    vis.emplace(a);
 
    while(!Q.empty()) {
        vector<int> v = Q.front(); Q.pop();
 
        for(int i = 0; i+1 < sz(v); i++) {
            for(int j = i+2; j+1 < sz(v); j++) {
                vector<int> cpy = v;
                swap(v[i], v[j]);
                swap(v[i+1], v[j+1]);
 
                if(!vis.count(v)) {
                    par[v] = cpy;
                    Q.push(v);
                    vis.emplace(v);
                }
                swap(v[i], v[j]);
                swap(v[i+1], v[j+1]);
            }
        }
    }
 
    vector<int> want;
    for(int i = 1; i <= n; i++) want.emplace_back(i);
 
    if(vis.count(want)) {
        cout << "YES" << endl;
        // vector<int> cur = want;

        // vector<vector<int>> construction;
        // while(cur != orig) {
        //     construction.emplace_back(cur);
        //     cur = par[cur];
        // }
        // construction.emplace_back(cur);

        // reverse(all(construction));
        // for(auto x: construction) {
        //     for(int y: x) {
        //         cout << y << " ";
        //     }
        //     cout << endl;
        // }
    } else {
        cout << "NO" << endl;
    }

    // cout << "unreachables: " << endl;
    // do {
    //     if(!vis.count(want)) {
    //         for(int x: want) {
    //             cout << x << " ";
    //         }
    //         cout << endl;
    //     }
    // } while (next_permutation(all(want)));

    // cout << "reachable: " << endl;
    // do {
    //     if(vis.count(want)) {
    //         for(int x: want) {
    //             cout << x << " ";
    //         }
    //         cout << endl;
    //     }
    // } while (next_permutation(all(want)));    
}
 
 
 
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    
 
    int t;
    cin >> t;
 
    while(t--) solve();
}
 
/*
40 320 000
 
322 560 000
*/
 
// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?