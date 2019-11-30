#include <bits/stdc++.h>
#define int unsigned long long
#define maxn 100500
#define watch(x) cout << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'

bool vis[maxn];
int y[maxn];
vector<int> G[maxn];
int ans = 0;
int dist[maxn];
int dist2[maxn];



bool g(int n) {
    int l = 1;
    int r = sqrt(n);

    while(l <= r) {
        int m = (l+r)/2;

        if((m*m) + m < n) {
            l = m+1;
        } else if((m*m)+m > n) {
            r = m-1;
        } else {
            return true;
        }
    }

    return false;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    
    for(int i = 1; i <= N; i++) {
        cin >> y[i];
        dist[i] = INT_MAX;
        dist2[i] = INT_MAX;
    }

    for(int i = 1; i <= N-1; i++) {
        int a, b;
        cin >> a >> b;

        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }
    

    bool noGood = true;
    bool good[N+1];
    for(int i = 1; i <= N; i++) {
        good[i] = g(y[i]);
        if(good[i]) noGood = false;
    }

    if(noGood) {
        cout << 0 << endl;
        return 0;
    }


    vector<int> goodG[N+1];
    for(int i = 1; i <= N; i++) {
        for(int adj: G[i]) {
            if(good[adj] and good[i]) {
                goodG[i].emplace_back(adj);
                goodG[adj].emplace_back(adj);
            }
        }
    }

  
    for(int i = 1; i <= N; i++) {
        if(!vis[i]) {
            vis[i] = true;
            queue<int> Q;
            Q.push(i);
            int furthest = 0;
            int furthestind = i;

           // for(int j = 1; j <= N; j++) dist[j] = INT_MAX;
           // fill(dist+1, dist+N+1, INT_MAX);

            dist[i] = 0; 
            while(!Q.empty()) {
                int S = Q.front(); Q.pop();

                vis[S] = true;
                for(int x: goodG[S]) {
                    if(dist[x] > dist[S]+1) {
                        Q.push(x);
                        dist[x] = dist[S]+1;
                        if(dist[x] > furthest) {
                            furthest = dist[x];
                            furthestind = x;
                            vis[x] = true;
                        }
                    }
                }
            }

            Q = queue<int>();
            // for(int i = 1; i <= N; i++) dist[i] = INT_MAX;
            // fill(dist+1, dist+N+1, INT_MAX);


            dist2[furthestind] = 0;
            Q.push(furthestind);
            int furthest2= 0;
            while(!Q.empty()) {
                int S = Q.front(); Q.pop();
                vis[S] = true;
                for(int x: goodG[S]) {
                    if(dist2[x] > dist2[S]+1) {
                        Q.push(x);
                        dist2[x] = dist2[S]+1;
                        furthest2 = max(furthest2, dist2[x]);
                        vis[x] = true;
                    }
                }
            }

            ans = max(ans, furthest2+1);
        }   
    }

        cout << ans << endl;
    
}