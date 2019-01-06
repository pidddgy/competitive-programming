// https://dmoj.ca/problem/ccc13s4

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    vector<int> graph[N+1]; // For elem i, i is taller than all int in graph[i]
    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }
    int p, q;
    cin >> p >> q;
    string ret = "unknown";

    queue<int> Q;
    bool vis[N+1]; for(int i = 0; i < N+1; i++) vis[i] = false;
    Q.push(p);
    vis[p] = true;

    while(!Q.empty()) {
        int S = Q.front(); Q.pop();
        if(S == q) {
            ret = "yes";
            break;
        }
        for(auto adj: graph[S]) {
            if(!vis[adj]) {
                Q.push(adj);
                vis[adj] = true;
            }
        }
    }

    if(ret == "unknown") {
        Q = queue<int>();
        for(int i = 0; i < N+1; i++) vis[i] = false;
        Q.push(q);
        vis[q] = true;
        while(!Q.empty()) {
        int S = Q.front(); Q.pop();
            if(S == p) {
                ret = "no";
                break;
            }
            for(auto adj: graph[S]) {
                if(!vis[adj]) {
                    Q.push(adj);
                    vis[adj] = true;
                }
            }
        }
    }
    cout << ret << endl;
}
