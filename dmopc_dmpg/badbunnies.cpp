#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl;
const int MAXINT = 2147483647;
using namespace std;

int main() {
    int N, R;
    cin >> N >> R;
    
    unordered_set<int> A[N+1];
    for(int i = 1; i <= N-1; i++) {
        int a, b;
        cin >> a >> b;
        A[a].emplace(b);
        A[b].emplace(a);
    }

    bool b[N+1]; fill(b, b+N+1, false);
    for(int i = 1; i <= R; i++) {
        int a; cin >> a;
        b[a] = true;
    }

    int X, Y;

    cin >> X >> Y;

    int par[N+1];

    queue<int> Q;
    bool vis[N+1];
    for(int i = 1; i <= N; i++) {
        par[i] = -1;
        vis[i] = false;
    }

    Q.push(X);
    vis[X] = true;

    while(!Q.empty()) {
        int S = Q.front();
        Q.pop();

        for(auto adj: A[S])
            if(!vis[adj]) {
                Q.push(adj);
                par[adj] = S;
                vis[adj] = true;
            }
    }

    
    vector<int> path = { Y };
    int temp = Y;

    while(temp != X) {
        path.emplace_back(par[temp]);
        temp = par[temp];
    }


    for(int i = 0; i < path.size()-1; i++) {
        A[ path[i] ].erase(path[i+1]);
        A[ path[i+1] ].erase(path[i]);
    }

    int minD = MAXINT;
    for(auto a: path) {
        Q = queue<int>();
        int dist[N+1];
        for(int i = 1; i <= N; i++) dist[i] = MAXINT;

        dist[a] = 0;
        Q.push(a);

        while(!Q.empty()) {
            int S = Q.front(); Q.pop();
            if(b[S] && dist[S] < minD) minD = dist[S];
            for(auto adj: A[S]) {
                if(dist[adj] > dist[S]) {
                    Q.push(adj);
                    dist[adj] = dist[S]+1;
                }
            }
        }
    }

    cout << minD << "\n";
}
