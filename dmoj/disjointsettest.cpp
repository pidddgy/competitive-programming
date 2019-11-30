// https://dmoj.ca/problem/ds2

#include <bits/stdc++.h>
#define endl '\n'
#define pii pair<int, int>
#define fi first
#define se second
#define maxN 100007

using namespace std;

int p[maxN];

int findp(int n) {
    if(n == p[n]) return n;
    else return p[n] = findp(p[n]);
}

void join(int a, int b) {
    int n = findp(a);
    int m = findp(b);

    assert(n != m);

    p[n] = m;
}


int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    vector<int> ret;
    vector<int> A[N+1];

    for(int i = 1; i <= N; i++)
        p[i] = i;

    pii E[M+1];

    for(int i = 1; i <= M; i++) {
        cin >> E[i].fi >> E[i].se;
        A[E[i].fi].emplace_back(E[i].se);
        A[E[i].se].emplace_back(E[i].fi);
    }

    queue<int> Q;
    bool vis[N+1]; fill(vis, vis+N+1, false);

    Q.push(1);
    vis[1] = true;

    while(!Q.empty()) {
        int s = Q.front();
        Q.pop();

        for(auto adj: A[s]) {
            if(!vis[adj]) {
                vis[adj] = true;
                Q.push(adj);
            }
        }
    }

    for(int i = 1; i <= N; i++) {
        if(!vis[i]) {
            cout << "Disconnected Graph" << endl;
            return 0;
        }
    }

    for(int e = 1; e <= M; e++) {
        if(findp(E[e].fi) != findp(E[e].se)) {
            join(E[e].fi, E[e].se);

            ret.emplace_back(e);
        }
    }

    for(auto e: ret) {
        cout << e << endl;
    }
}


