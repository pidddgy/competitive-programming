// https://codeforces.com/contest/1006/problem/E

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define cerr if(false) cerr
using namespace std;
#define endl '\n'
#define maxn 200500
int sz[200500];
bool vis[maxn];
set<int, greater<int>> G[maxn+1];


int f(int n) {
    int sum = 1;
    for(int adj: G[n]) {
        if(!vis[adj]) {
            vis[adj] = true;
            sum += f(adj);
        }
    }

    sz[n] = sum;
    return sum;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    int dis[n+1];
    for(int i = 1; i <= n; i++) {
        dis[i] = INT_MAX;
    }

    for(int i = 2; i <= n; i++) {
        int _;
        cin >> _;

        G[_].emplace(i);
        G[i].emplace(_);
    }

    f(1);
    for(int i = 1; i <= n; i++) {
        cerr << sz[i] << " ";
    }
    cerr << endl;

    stack<int> St;
    dis[1] = 0;
    St.push(1);

    int order[n+1];
    int ind[n+1];
    int cur = 1;
    while(!St.empty()) {
        int S = St.top(); St.pop();
        cerr << "currently on " << S << endl;
        order[cur] = S;

        cerr << S << "th index can be found at " << cur << " in order" << endl;
        ind[S] = cur;
        cur++;
        cerr << "children are " << endl;
        for(int adj: G[S]) {
            cerr << adj << endl;
            if(dis[adj] > dis[S]+1) {
                dis[adj] = dis[S]+1;
                St.push(adj);
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        cerr << order[i] << " ";
    }
    cerr << endl;


    for(int i = 1; i <= n; i++) {
        cerr << ind[i] << " ";
    }
    cerr << endl;

    for(int i = 1; i <= n; i++) {
        cerr << dis[i] << " ";
    }
    cerr << endl;

    for(int i = 1; i <= q; i++) {
        int u, k;
        cin >> u >> k;
        if(ind[u]+k-1 >n or sz[u] < k) {
            cout << -1 << endl;
        } else {
            cout << order[ind[u]+k-1] << endl;
        }
    }




}