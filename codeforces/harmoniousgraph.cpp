// http://codeforces.com/contest/1253/problem/D
    
#include <bits/stdc++.h>
#define maxn 200500 
using namespace std;
    
int disj[maxn];
bool vis[maxn];
bool vis2[maxn];
    
int findp(int n) {
    if(disj[n] == n) return n;
    else return disj[n] = findp(disj[n]);
}
    
void merge(int a, int b) {
    int a_p = findp(a);
    int b_p = findp(b);
    
    disj[a_p] = b_p;
}
    
int main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int N, M;
    cin >> N >> M;
    
    for(int i = 1; i <= N; i++) disj[i] = i;
    
    vector<int> G[N+1];
    for(int i = 1; i <= M; i++) {
        int u, v;
        cin >> u >> v;
    
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    
        merge(u, v);
    }
    
    int i = 1;
    int ans = 0;
    while(i <= N) {
        if(vis[findp(i)]) {
            i++;
            continue;
        }
        queue<int> Q;
    
        int ma = i;
        vis[i] = true;
        Q.push(i);
    
        while(!Q.empty()) {
            int S = Q.front(); Q.pop();
            ma = max(ma, S);
            for(int adj: G[S]) {
                if(!vis[adj]) {
                    Q.push(adj);
                    vis[adj] = true;
                }
            }
        }
    
        // cout << "ma for " << i << " is " << ma << endl;
        for(int j = i; j <= ma; j++) {
            if(findp(i) != findp(j)) {
                // cout << "merging " << i << "," << j << endl;
                merge(i, j);
                
                ans++;
            }
        }
    
        int ma2 = i;
        vis[i] = true;
        Q.push(i);
    
        while(!Q.empty()) {
            int S = Q.front(); Q.pop();
            ma2 = max(ma2, S);
            for(int adj: G[S]) {
                if(!vis[adj]) {
                    Q.push(adj);
                    vis[adj] = true;
                }
            }
        }
    
        i = ma2+1;
    }
    
    cout << ans << endl;
    
    
}

// sfds