// https://codeforces.com/contest/1332/problem/C

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define pci pair<char, int>
#define fi first
#define se second
#define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;

bool comp(const pci &l, const pci &r) {
    return l.se > r.se; 
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while(T--) {
        int n, k;
        cin >> n >> k;

        string s;
        cin >> s;
        s = "."+s;

        vector<int> G[n+1];

        for(int i = 1; i <= n; i++) {
            G[i].emplace_back(n+1-i);
            G[n+1-i].emplace_back(i);
        }

        for(int i = 1; i <= n-k; i++) {
            G[i].emplace_back(k+i);
            G[k+i].emplace_back(i);
        }

        bool vis[n+1];
        for(int i = 1; i <= n; i++) {
            vis[i] = false;
        }

        int ans = 0;
        for(int i = 1; i <= n; i++) {
            if(!vis[i]) {
                cerr << i << " is not visited" << endl;
                unordered_map<char, int> cnt;
                queue<int> Q;

                Q.push(i);
                vis[i] = true;
                int cmpsz = 0;
                while(!Q.empty()) {
                    int S = Q.front(); Q.pop();
                    cmpsz++;
                    cnt[s[S]]++;

                    for(int adj: G[S]) {
                        // should always be false but whatever
                        if(!vis[adj]) {
                            Q.push(adj);
                            vis[adj] = true;
                        }
                    } 
                }

                vector<pci> cntV;
                for(pci x: cnt) {
                    cntV.emplace_back(x);
                }

                sort(cntV.begin(), cntV.end(), comp);
                watch(cmpsz)
                watch((*cntV.begin()).fi)
                watch((*cntV.begin()).se)
                ans += cmpsz - ((*cntV.begin()).se);
            }
        }

        cout << ans << endl;
    }
}