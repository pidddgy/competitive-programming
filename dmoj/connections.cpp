// https://dmoj.ca/problem/dmopc19c2p5  

#include <bits/stdc++.h>
using namespace std;
int main() {
    #define int long long
    int N;
    cin >> N;

    int a[N+1];
    for(int i = 1; i <= N; i++) cin >> a[i];

    vector<int> G[N+1];
    for(int i = 1; i <= N-1; i++) {
        int u, v;
        cin >> u >> v;

        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    int ans = LLONG_MAX;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            int sum = 0;
            for(int k = 1; k <= N; k++) {
                queue<int> Q;
                int dis[N+1]; fill(dis, dis+N+1, LLONG_MAX);

                Q.push(k);
                dis[k] = 0;

                while(!Q.empty()) {
                    int S = Q.front(); Q.pop();
                    for(int adj: G[S]) {
                        if(dis[S]+1 < dis[adj]) {
                            Q.push(adj);
                            dis[adj] = dis[S]+1;
                        }
                    }
                }

                int mi = min(dis[i], dis[j]);
                sum += mi*a[k];
            }

            ans = min(ans, sum);
        }
    }

    cout << ans << endl;
}