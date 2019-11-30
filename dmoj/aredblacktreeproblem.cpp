// https://dmoj.ca/problem/wac1p4

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> subgraphs[105];
vector<int> G[105];
int N, K;
void recurse(vector<int> n, int deg = 1) {
    for(auto x: n)
        cout <<  x <<  " ";
    
    cout << endl;
    if(deg == K) {
        subgraphs[n.front()].emplace_back(n);
    }

    for(auto adj: G[n.back()]) {
        if(find(n.begin(), n.end(), adj) == n.end()) {
            vector<int> newN = n;
            newN.emplace_back(adj);
            recurse(newN, deg+1);
        }
    }
}
int main() {
    cin >> N >> K;

    string s;
    cin >> s;
    s = "."+s;

    for(int i = 1; i <= N-1; i++) {
        int a, b;
        cin >> a >> b;

        G[a].emplace_back(b);
        G[b].emplace_back(a);
   }

   for(int i = 1; i <= N; i++) {
       recurse({i});
   }

    int ans = 0;
   for(int i = 1; i <= N; i++) {
       for(vector<int> cute: subgraphs[i]) {
           int red = 0;
           int black = 0;

           for(int x: cute) {
               if(s[x] == 'R') red++;
               else black++;
           }

           if(red >= 2 && black >= 2) ans++;
       }
   }    

   cout << ans << endl;

}