// https://dmoj.ca/problem/dwite11c2p4

#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl;
using namespace std;



int main() {
    for(int aasdf = 0; aasdf < 2; aasdf++) {
        int N;
        cin >> N;

        vector<int> G[N];
        for(int i = 0; i < N-1; i++) {
            int a, b;
            cin >> a >> b;
            G[a].push_back(b);
            G[b].push_back(a);
        }

        int mi = 2147483647;
        for(int start = 0; start < N; start++) {
            int ma = -2147483647;
            queue<int> Q;

            bool vis[N];
            for(int i = 0; i < N; i++) vis[i] = false;
            Q.push(start);
            ma = max(ma, (int)Q.size());
            vis[start] = true;
            
            while(!Q.empty()) {
                ma = max(ma, (int)Q.size());
                int S = Q.front();
                Q.pop();
                for(auto adj: G[S]) {
                    if(!vis[adj]) {
                        Q.push(adj);
                        vis[adj] = true;
                    }
                    
                }
                ma = max(ma, (int)Q.size());
            }   

            mi = min(mi, ma);

            watch(start)
            watch(ma)
        }
        cout << mi << endl;
    }
}