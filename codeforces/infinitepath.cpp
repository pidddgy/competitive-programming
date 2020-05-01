// https://codeforces.com/contest/1327/problem/D

#include <bits/stdc++.h>
using namespace std;
int main() {
    int T;
    cin >> T;

    while(T--) {
        int N;
        cin >> N;

        int a[N+1];
        for(int i = 1; i <= N; i++) {
            cin >> a[i];
        }

        int c[N+1];
        for(int i = 1; i <= N; i++) cin >> c[i];

        for(int i = 1; i <= 7; i++) {
            int b[N+1];
            bool vis[N+1];
            for(int j = 1; j <= N; j++) {
                vis[j] = false;
                if(i == 1) b[j] = a[j];
                else b[j] = a[a[j]];
            }
            
            cerr << "arr at ind " << i << " is:" << endl;
            for(int i = 1; i <= N; i++) {
                cerr << b[i] << " ";
            }
            cerr << endl;

            int br = false;
            for(int j = 1; j <= N; j++) {
                set<int> seenColors;
                if(!vis[j]) {
                    queue<int> Q;
                    Q.push(j);
                    cerr << "starting from " << j << endl;
                    vis[j] = true;

                    while(!Q.empty()) {
                        int S = Q.front(); Q.pop();
                        cerr << "S is " << S << endl;
                        cerr << "using color " << c[S] << endl;
                        seenColors.emplace(c[S]);

                        if(!vis[b[S]]) {
                            cerr << "pushing " << b[S] << endl;
                            Q.push(b[S]);
                            vis[b[S]] = true;
                        }
                    }
                }

                if(seenColors.size() == 1) {
                    cerr << "using " << j << endl;
                    cout << i << endl;
                    br = true;
                    break;
                }
                cerr << endl;
            }
            cerr << "HIII" << endl;
            if(br) break;

            for(int i = 1; i <= N; i++) {
                a[i] = b[i];
            }
        }
    }

}