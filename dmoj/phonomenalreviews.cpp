// https://dmoj.ca/problem/ccc16s3

#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl;
#define MAXN 100005
using namespace std;

set<int> g[MAXN];
bool vis[MAXN];
bool isPho[MAXN];
bool hasPho[MAXN];
int dist[MAXN];

// if subtree has a pho restaurant
bool hp(int n) {
    vis[n] = true;
    if(isPho[n]) hasPho[n] = true;
    if(g[n].size() == 0) {
        hasPho[n] = isPho[n];
    } else {
        for(auto adj: g[n]) {
            if(!vis[adj]) {
                if(hp(adj)) {
                    hasPho[n] = true;
                }
            }
        }
    }

    return hasPho[n];
}

int main() {
    int N, M;
    cin >> N >> M;

    int root = 0;
    for(int i = 0; i < M; i++) {
        int a; cin >> a;
        isPho[a] = true;
        root = a;
    }

    for(int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        g[a].emplace(b);
        g[b].emplace(a);
    }

    fill(vis, vis+MAXN, false);
    hp(root);

    int hasPhoCnt = 0;
    for(int i = 0; i < N; i++)
        if(hasPho[i]) hasPhoCnt++;

    // get node furthest away from root
    queue<int> Q;
    Q.push(root);
    fill(dist, dist+MAXN, 2147483647);
    int ma = -1;
    int maind;
    dist[root] = 0;

    while(!Q.empty()) {
        int S = Q.front();
        Q.pop();

        for(int adj: g[S]) {
            if(dist[adj] > dist[S] && hasPho[adj]) {
                Q.push(adj);
                dist[adj] = dist[S]+1;
                ma = max(ma, dist[adj]);
                maind = adj;
            }
        }
    }
    
    Q.push(maind);
    fill(dist, dist+MAXN, 2147483647);

    dist[maind] = 0;
    ma = -1;

    while(!Q.empty()) {
        int S = Q.front();
        Q.pop();

        for(int adj: g[S]) {
            if(dist[adj] > dist[S] && hasPho[adj]) {
                Q.push(adj);
                dist[adj] = dist[S]+1;
                ma = max(ma, dist[adj]);
                maind = adj;
            }
        }
    }

    cout<<((hasPhoCnt-1)*2)-ma << endl;
}