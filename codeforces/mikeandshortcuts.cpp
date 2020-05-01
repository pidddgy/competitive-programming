// https://codeforces.com/contest/689/problem/B

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pii pair<int, int>
#define fi first
#define se second
int main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    vector<int> G[N+1];
    for(int i = 1; i <= N-1; i++) {
        G[i].emplace_back(i+1);
        G[i+1].emplace_back(i);
    }

    for(int i = 1; i <= N; i++) {
        int a;
        cin >> a;

        G[i].emplace_back(a);
    }

    queue<int> Q;
    int dist[N+1];
    for(int i = 1; i <= N; i++) dist[i] = INT_MAX;

    Q.push(1);
    dist[1] = 0;

    while(!Q.empty()) {
        int S = Q.front(); Q.pop();

        for(int adj: G[S]) {
            if(dist[adj] > dist[S]+1) {
                dist[adj] = dist[S]+1;
                Q.push(adj);
            }
        }
    }

    for(int i = 1; i <= N; i++) {
        cout << dist[i] << " ";
    }
    cout << endl;

}