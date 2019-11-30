// https://dmoj.ca/problem/vmss7wc16c3p3

#include <bits/stdc++.h>
#define pii pair<int, int>
#define fi first
#define se second
#define MAXINT 2147483647
#define watch(x) cout << (#x) << " is " << (x) << endl;

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    int B; cin >> B;
    int Q; cin >> Q;

    vector<pii> adj[N+1];

    for(int i = 1; i <= M; i++) {
        int x, y, z;
        cin >> x >> y >> z;

        adj[x].emplace_back(z, y);
        adj[y].emplace_back(z, x);
    }

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    int dist[N+1]; fill(dist, dist+N+1, MAXINT);

    dist[B] = 0;
    pq.push({0, B});

    while(!pq.empty()) {
        pii s = pq.top(); pq.pop();
        for(pii e: adj[s.se]) {
            int dis = dist[s.se] + e.fi;

            if(dis < dist[e.se]) {
                dist[e.se] = dis;
                pq.push({dis, e.se});
            }
        }
    }

    for(int i = 1; i <= Q; i++) {
        int A; cin >> A;

        if(dist[A] == MAXINT) cout << -1 << endl;
        else cout << dist[A] << endl;
    }

}