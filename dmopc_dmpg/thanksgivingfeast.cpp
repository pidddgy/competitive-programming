// https://dmoj.ca/problem/dmopc18c2p3

#include <bits/stdc++.h>
#pragma GCC optimize "Ofast"
using namespace std;
const int MAX_INT = 2147483647;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, M, K, A, B;
    cin >> N >> M >> K >> A >> B;

    int gift[K+1];
    vector<int> edges[N+1];

    for(int i = 1; i < K+1; i++)
        cin >> gift[i];
    
    for(int i = 1; i < M+1; i++) {
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    queue<int> Q;
    int distA[N+1]; for(int i = 1; i < N+1; i++) distA[i] = MAX_INT;
    Q.push(A);
    distA[A] = 0;

    while(!Q.empty()) {
        int S = Q.front(); Q.pop();
        for(auto adj: edges[S])
            if(distA[adj] > distA[S]+1) {
                distA[adj] = distA[S]+1;
                Q.push(adj);
            }
    }

    Q = queue<int>();
    int distB[N+1]; for(int i = 1; i < N+1; i++) distB[i] = MAX_INT;
    for(int i = 1; i < N+1; i++) distB[i] = MAX_INT;
    Q.push(B);
    distB[B] = 0;

    while(!Q.empty()) {
        int S = Q.front(); Q.pop();
        for(auto adj: edges[S]) {
            if(distB[adj] > distB[S]+1) {
                distB[adj] = distB[S]+1;
                Q.push(adj);
            }
        }
    }

    int minV = MAX_INT;
    for(int i = 1; i < K+1; i++) {
        if(distA[gift[i]] + distB[gift[i]] < minV)
            minV = distA[gift[i]] + distB[gift[i]];
    }

    cout << minV << "\n";
    return 0;
}
