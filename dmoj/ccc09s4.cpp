// https://dmoj.ca/problem/ccc09s4

#include <bits/stdc++.h>
using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define pii pair<int, int>
#define fi first
#define se second

const int maxn = 5005;
const int INF = INT_MAX-300;
int N, T, K;

int p[maxn], dis[maxn];
int G[maxn][maxn];

signed main() {
    // ios::sync_with_stdio(0);
    // cin.sync_with_stdio(0);
    // cin.tie(0);

    for(int i = 0; i < maxn; i++) {
        p[i] = INF;
        dis[i] = INF;
        for(int j = 0; j < maxn; j++) {
            G[i][j] = INF;
        }
    }

    // cin >> N;
    scan(N);

    // cin >> T;
    scan(T);

    for(int i = 1; i <= T; i++) {
        int x, y, c;
        // cin >> x >> y >> c;
        scan(x);
        scan(y);
        scan(c);

        G[x][y] = min(G[x][y], c);
        G[y][x] = min(G[y][x], c);
    }

    // cin >> K;
    scan(K);

    for(int i = 1; i <= K; i++) {
        int z, P;
        // cin >> z >> P;
        scan(z);
        scan(P);

        p[z] = P;
    }

    int D;
    // cin >> D;
    scan(D);
    
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dis[D] = 0;
    pq.push({0, D});

    while(!pq.empty()) {
        int S = pq.top().se; pq.pop();
        
        for(int i = 1; i <= N; i++) {
            if(G[S][i] == INF) continue;

            if(dis[i] > dis[S]+G[S][i]) {
                dis[i] = dis[S]+G[S][i];
                pq.push({dis[i], i});
            }
        }
    }

    int ans = INT_MAX;

    for(int i = 1; i <= N; i++) {
        if(p[i] != INF) {
            ans = min(ans, dis[i]+p[i]);
        }
    }

    cout << ans << endl;
}
