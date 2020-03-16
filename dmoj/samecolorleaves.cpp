// https://dmoj.ca/problem/dmopc19c3p4

#include <bits/stdc++.h>
#define maxn 3500

using namespace std;

char color[maxn];
vector<int> G[maxn];
int poss[maxn];
bool vis[maxn];


int main() {
    int N;
    cin >> N;

    for(int i = 1; i <= N; i++) cin >> color[i];

    for(int i = 1; i <= N-1; i++) {
        int u, v;
        cin >> u >> v;

        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    int ans = 0;
    for(int i = 1; i <= N; i++) {
        queue<int> Q;
        for(int j = 1; j <= N; j++) vis[i] = false;

        char leafc = '?';
        bool good = true;
        Q.push(i);
        vis[i] = true;
        int sz = 1;
        while(!Q.empty()) {
            int S= Q.front(); Q.pop();
            bool leaf = true;
            for(int adj: G[S]) {
                if(!vis[adj]) {
                    Q.push(adj);
                    vis[adj] = true;
                    leaf = false;
                }
            }

            if(leaf) {
                if(leafc == '?') {
                    leafc = color[S];
                } else {
                    if(leafc != color[S]) good = false;
                }
            }
        }
    }

    cout << ans << endl;



}