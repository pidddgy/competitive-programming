// https://dmoj.ca/problem/hci16redstone

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, E;
    cin >> N >> E;

    vector<int> G[N+1];

    for(int i = 1; i <= E; i++) {
        int A, B;
        cin >> A >> B;

        G[A].emplace_back(B);
    }

    bool cycle[N+1]; fill(cycle, cycle+N+1, false);
    int ans = 0;

    for(int i = 1; i <= N; i++) {
        if(!cycle[i]) {
            bool vis[N+1];
            fill(vis, vis+N+1, false);

            queue<int> Q;

            Q.push(i);
            vis[i] = true;
            int parent[N+1]; for(int i = 1; i <= N; i++) parent[i] = i;

            while(!Q.empty()) {
                int S = Q.front(); Q.pop();

                for(auto adj: G[S]) {
                    if(adj == i) {
                     //   cout << "HI" << endl;
                        ans++;
                        int temp = S;
                        while(parent[temp] != temp) {
                            cycle[temp] = true;
                            temp = parent[temp];
                            
                        }
                    } else 
                    if(!vis[adj]) {
                        Q.push(adj);
                        vis[adj] = true;
                        parent[adj] = S;
                    }
                }
            

            }
        }
    }

    if(ans == 0)
        cout << "No Infinite Loops" << endl;
    else if(ans == 1)
        cout << "Infinite Loop Present" << endl;
    else
        cout << "Infinite Loops Present" << endl;





}