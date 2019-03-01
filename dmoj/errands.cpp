// https://dmoj.ca/problem/globexcup18j5

#include <bits/stdc++.h>
#define eb emplace_back
const int MAXINT = 2147483647;

using namespace std;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, M, Q, C;
    cin >> N >> M >> Q >> C;
    vector<int> graph[N+1];

    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].eb(b);
        graph[b].eb(a);
    }

    // bfs from c to a and b;
    int dist[N+1];
    for(int i = 0; i < N+1; i++) dist[i] = MAXINT;

    dist[C] = 0;
    queue<int> Qu;
    Qu.push(C);

    while(!Qu.empty()) {
        int S = Qu.front();
        Qu.pop();
        for(auto adj: graph[S]) {
            if(dist[adj] == MAXINT) {
                dist[adj] = dist[S]+1;
                Qu.push(adj);
            }
        }
    }

    for(int i = 0; i < Q; i++) {
        int a, b;
        cin >> a >> b;

        if(dist[a] == MAXINT || dist[b] == MAXINT) {
            cout << "This is a scam!" << "\n";
        }
        else
            cout << dist[a] + dist[b] << "\n";
    }
}
