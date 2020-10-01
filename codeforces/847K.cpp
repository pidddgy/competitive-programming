// https://codeforces.com/contest/847/problem/K

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

int n, a, b, k, f;
map<string, map<string, int>> cost;
set<string> S;
int tot = 0;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> a >> b >> k >> f;

    string last = "?";
    for(int i = 1; i <= n; i++) {
        string u, v;
        cin >> u >> v;

        S.emplace(u);
        S.emplace(v);

        if(u == last) {
            cost[min(u, v)][max(u, v)] += b;
            tot += b;
        } else {
            cost[min(u, v)][max(u, v)] += a;
            tot += a;
        }
        last = v;

    }

    vector<string> nodes;
    for(string x: S) nodes.emplace_back(x);

    vector<int> costs;
    for(int i = 0; i < sz(nodes); i++) {
        for(int j = i+1; j < sz(nodes); j++) {
            costs.emplace_back(cost[min(nodes[i], nodes[j])][max(nodes[i], nodes[j])]);
        }
    }

    sort(all(costs));
    reverse(all(costs));

    for(int x: costs) {
        cerr << x << " ";
    }
    cerr << endl;

    watch(tot)
    int used = 0;
    for(int i = 0; i < sz(costs) and used < k; i++) {
        if(costs[i] > f) {
            cerr << "e" << endl;
            cerr << "replacing " << costs[i] << endl;
            used++;
            tot -= costs[i];
            tot += f;
        }
    }

    cout << tot << endl;
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
