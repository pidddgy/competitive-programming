// https://codeforces.com/contest/362/problem/A

#include <bits/stdc++.h>
#define pii pair<int, int>
#define fi first
#define cerr if(false)
#define se second
#define scope for(int scope = 1; scope <= 1; scope++)
using namespace std;


void solve() {
    char grid[50][50];

    vector<pii> kpos;
    kpos.emplace_back(0, 0);
    for(int i = 1; i <= 8; i++) {
        for(int j = 1; j <= 8; j++) {
            cin >> grid[i][j];
            if(grid[i][j] == 'K') {
                kpos.emplace_back(i, j);
            }
        }
    }

    int dis[3][50][50];
    for(int i = 0; i < 50; i++) {
        for(int j = 0; j < 50; j++) {
            dis[1][i][j] = INT_MAX;
            dis[2][i][j] = INT_MAX;
        }
    }

    bool second = false;
    for(int ind = 1; ind <= 2; ind++) {
        pii st = kpos[ind];

        queue<int> rQ;
        queue<int> cQ;

        rQ.push(st.fi);
        cQ.push(st.se);

        dis[ind][st.fi][st.se] = 0;

        while(!rQ.empty()) {
            int r = rQ.front(); rQ.pop();
            int c = cQ.front(); cQ.pop();

            if(r+2 <= 8 and c+2 <= 8) {
                if(dis[ind][r][c] + 1 < dis[ind][r+2][c+2]) {
                    rQ.push(r+2);
                    cQ.push(c+2);

                    dis[ind][r+2][c+2] = dis[ind][r][c] + 1;
                }
            }

            if(r+2 <= 8 and c-2 >= 1) {
                if(dis[ind][r][c] + 1 <dis[ind][r+2][c-2]) {
                    rQ.push(r+2);
                    cQ.push(c-2);

                    dis[ind][r+2][c-2] = dis[ind][r][c] + 1;
                }
            }

            if(r-2 >= 1 and c+2 <= 8) {
                if(dis[ind][r][c] + 1 < dis[ind][r-2][c+2]) {
                    rQ.push(r-2);
                    cQ.push(c+2);

                    dis[ind][r-2][c+2] = dis[ind][r][c] + 1;
                }
            }

            if(r-2 >= 1 and c-2 >= 1) {
                if(dis[ind][r][c] + 1 < dis[ind][r-2][c-2]) {
                    rQ.push(r-2);
                    cQ.push(c-2);

                    dis[ind][r-2][c-2] = dis[ind][r][c] + 1;
                }
            }
        }
    }

    for(int i = 1; i <= 8; i++) {
        for(int j = 1; j <= 8; j++) {

            if(dis[1][i][j] == INT_MAX) cerr << "X ";
            else 
            cerr << dis[1][i][j] << " ";
            // if((dis[1][i][j]%2 == dis[2][i][j]%2) and grid[i][j] != '#') {
                // cerr << "use square " << i << " " << j << endl;
                // cout << "YES" << endl;
                // return;
            // }
        }
        cerr << endl;
    }
    
    cerr << endl; 
    for(int i = 1; i <= 8; i++) {
        for(int j = 1; j <= 8; j++) {
            if(dis[2][i][j] == INT_MAX) cerr << "X ";
            else 
            cerr << dis[2][i][j] << " ";
            // if((dis[1][i][j]%2 == dis[2][i][j]%2) and grid[i][j] != '#') {
                // cerr << "use square " << i << " " << j << endl;
                // cout << "YES" << endl;
                // return;
            // }
        }
        cerr << endl;
    }

    for(int i = 1; i <= 8; i++) {
        for(int j = 1; j <= 8; j++) {
            if((dis[1][i][j]%2 == dis[2][i][j]%2) and grid[i][j] != '#' and dis[1][i][j] != INT_MAX and dis[2][i][j] != INT_MAX) {
                cerr << "use square " << i << " " << j << endl;
                cout << "YES" << endl;
                return;
            }
        }
    }


    cout << "NO" << endl;

}
int main() {
    int t;
    cin >> t;

    while(t--) {
        solve();
    }
}