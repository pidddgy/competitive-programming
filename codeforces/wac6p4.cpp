#include <bits/stdc++.h>
using namespace std;
#define cerr if(false) cerr
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

const int maxn = 200500;

set<int> G[maxn];
vector<pii> ans;
vector<int> ar;

vector<pii> shit;
void dfs(int v, int p) {
    for(int to: G[v]) {
        if(to == p) continue;
        
        shit.emplace_back(v, to);
        dfs(to, v);
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
        cin >> n;
    if(n == 1) {
        cout << 0 << endl;
        exit(0);
    }

    auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
    mt19937 mt(seed);

    int reeeeee = 0;
    for(int i = 1; i <= n-1; i++) {
        int u, v;
        cin >> u >> v;

        G[u].emplace(v);
        G[v].emplace(u);

        if(max(sz(G[u]), sz(G[v])) > 2) reeeeee = true;
    }


    cout << (n-1)/2 << endl;
    if(reeeeee and n > 8) return 0;
    for(int wee = 0; wee <= 300; wee++) {
        int st = -1;
        shit.clear();
        ans.clear();
        for(int i = 1; i <= n; i++) {
            if(sz(G[i]) == 1) {
                if(st == -1 or mt()%2) {
                    st = i;
                }
            }
        }

        watch(st)

        dfs(st, -1);

        for(pii x: shit) {
            cerr << x.fi << " " << x.se << endl;
        }

        if(wee >= 150) {
            shuffle(all(shit), mt);
        }

        for(int i = 0; i+1 < sz(shit); i ++) {
            map<int, int> cnt;
            cnt[shit[i].fi]++;
            cnt[shit[i].se]++;

            cnt[shit[i+1].fi]++;
            cnt[shit[i+1].se]++;

            vector<int> v;
            for(pii x: cnt) {
                if(x.se == 1) v.emplace_back(x.fi);
            }

            if(!G[v[0]].count(v[1])) {
                ans.emplace_back(v[0], v[1]);
                i++;
            }
        }
        // assert(sz(ans) == ((n-1)/2));

        if(sz(ans) != ((n-1)/2)) continue;

        for(pii x: ans) {
            cout << x.fi << " " << x.se << endl;
        }
        break;
    }


    
}

/*

add n/2 edges

select pairs of edges that contain an adjacent node

6
1 2
1 3
3 4
3 5
3 6

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?