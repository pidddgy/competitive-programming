// https://codeforces.com/contest/1263/problem/D

#include <bits/stdc++.h>
using namespace std;

#define maxn 200500

vector<int> G[maxn*2+500];
bool vis[maxn*2+500];

int main() {
    int N;
    cin >> N;

    for(int i = 1; i <= N; i++) {
        string s;
        cin >> s;

        for(char x: s) {
            G[i].emplace_back(x-'a' + N+1);
            G[x-'a' + N+1].emplace_back(i);
        }
    }

    int ans = 0;

    for(int i = 1; i <= N+26; i++) {
        if(!vis[i] and G[i].size()) {
            ans++;
            queue<int> Q;

            Q.push(i);

            while(!Q.empty()) {
                int S = Q.front(); Q.pop();
                for(int adj: G[S]) {
                    if(!vis[adj]) {
                        vis[adj] = true;
                        Q.push(adj);
                    }
                }
            }
        }
    }

    cout << ans << endl;

    
}