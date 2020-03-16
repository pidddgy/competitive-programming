#include <bits/stdc++.h>
using namespace std;

vector<int> A[100005];

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    string H;
    cin >> H;

    H = "." + H;
    
    for(int i = 1; i <= M; i++) {
        int ai, bi;
        cin >> ai >> bi;
        A[ai].emplace_back(bi);
        A[bi].emplace_back(ai);
    }

    int res = 0;
    for(int i = 1; i <= K; i++) {
        int a, b;
        cin >> a >> b;
        
        if(H[a] != H[b]) continue;

        queue<int> Q;
        bool vis[N+1]; for(int i = 1; i <= N; i++) vis[i] = false;

        Q.push(a);
        while(!Q.empty()) {
            int S = Q.front(); Q.pop();
            if(S == b) {
                res++;
                break;
            } 

            for(auto adj: A[S]) {
                if(H[S] == H[adj] && !vis[adj]) {
                    Q.push(adj);
                    vis[adj] = true;
                }
            }
        }
    }

   cout << res << endl;



}

