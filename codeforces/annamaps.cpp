// http://codeforces.com/contest/1204/problem/C

#include <bits/stdc++.h>
#define MAXINT 2147483647
#define watch(x) cout << (#x) << " is " << (x) << endl;
using namespace std;

vector<int> adj[200];
int dist[200][200];
int main() {
    int n;
    cin >> n; 

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            char cute;
            cin >> cute;

            if(cute == '1') {
                adj[i].emplace_back(j);
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        queue<int> Q;
        for(int j = 1; j <= n; j++) dist[i][j] = MAXINT;

        Q.push(i);
        dist[i][i] = 0;
        while(!Q.empty()) {
            int S = Q.front();
            Q.pop();

            for(int x: adj[S]) {
                if(dist[i][x] > dist[i][S]+1) {
                    dist[i][x] = dist[i][S]+1;
                    Q.push(x);
                }
            }
        }
    }

    int m;
    cin >> m;

    int p[m+1];
    for(int i = 1; i <= m; i++) cin >> p[i];
    
    // to skip, dis from i to j must be the same as i to i+1 to i+2...j

    vector<int> ans;
    ans.push_back(p[1]);
    for(int i = 1; i < m;) {
        int dis = 0;
        for(int j = i+1; j <= m; j++) {

            dis += dist[p[j-1]][p[j]];

            if(dis != dist[p[i]][p[j]]) {
                ans.push_back(p[j-1]);
                i = j-1;
                break;
            } 

            if(j == m) {
                i = m+5;
                break;
            }
        }
    }
    ans.push_back(p[m]);
    
    cout << ans.size() << endl;
    for(int x: ans) cout << x << " ";
    cout << endl;


    



    
}