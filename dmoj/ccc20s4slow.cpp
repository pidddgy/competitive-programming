// https://dmoj.ca/problem/ccc20s4

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

map<string, int> dis;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    int n = sz(s);

    queue<string> Q;
    Q.push(s);
    dis[s] = 0;

    while(!Q.empty()) {
        string S = Q.front(); Q.pop();

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                string adj = S;
                swap(adj[i], adj[j]);

                if((dis.find(adj) == dis.end()) or (dis[adj] > dis[S]+1)) {
                    dis[adj] = dis[S]+1;
                    Q.push(adj);
                }
            }
        }
    }
    
    map<char, int> cnt;

    for(char x: s) {
        cnt[x]++;
    }

    vector<string> hugs;
    string order = "ABC";
    do {
        for(int l = 0; l <= cnt[order[0]]; l++) {
            string ree;
            for(int i = 1; i <= l; i++) {
                ree += order[0];
            }

            for(int i = 1; i <= 2; i++) {
                for(int j = 1; j <= cnt[order[i]]; j++) {
                    ree += order[i];
                }
            }

            for(int i = 1; i <= cnt[order[0]]-l; i++) {
                ree += order[0];
            }
            hugs.emplace_back(ree);
            // watch(ree)
        }
    } while(next_permutation(all(order)));

    // watch(ree)
    int ans = LLONG_MAX;
    for(string a: hugs) {
        cerr << a << " costs " << dis[a] << endl;
        ans = min(ans, dis[a]);
    }

    cout << ans << endl;

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
