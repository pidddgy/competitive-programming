// https://codeforces.com/contest/320/problem/B

#include <bits/stdc++.h>
#define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;
signed main() {
    int n;
    cin >> n;

    vector<pii> a;
    vector<int> G[n+1];

    int emp = -1;

    for(int i = 0; i < n; i++) {
        int type;
        cin >> type;

        if(type == 1) {
            emp++;
            int x, y;
            cin >> x >> y;

            cerr << "currently on " << emp << endl;
            for(int j = 0; j < a.size(); j++) {
                watch(j)
                int A = a[j].fi;
                int B = a[j].se;
                watch(A)
                watch(B)
                watch(x)
                watch(y)
                cerr << endl;

                if(A < x and x < B) {
                    G[emp].emplace_back(j);
                    cerr << "emplacing" << endl;
                } else if(A < y and y < B) {
                    G[emp].emplace_back(j);
                    cerr << "emplacing2" << endl;
                }
                
                if(x < A and A < y) {
                    G[j].emplace_back(emp);
                } else if(x < B and B < y) {
                    G[j].emplace_back(emp);
                }
            }

            a.emplace_back(x, y);
            watch(i)
            cerr << endl;
        } else if(type == 2) {
            int A, B;
            cin >> A >> B;

            A--;
            B--;

            queue<int> Q;
            bool vis[n+1];
            for(int j = 0; j < n+1; j++) {
                vis[j] = false;
            }

            bool found = false;
            Q.push(A);
            vis[A] = true;
            while(!Q.empty()) {
                int S = Q.front(); Q.pop();
                cerr << "cur on " << S << endl;

                if(S == B) {
                    found = true;
                    break;
                }

                for(int adj: G[S]) {
                    if(!vis[adj]) {
                        Q.push(adj);
                        vis[adj] = true;
                    }
                }
            }

            if(found) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
            cerr << endl;
        }
    }
}