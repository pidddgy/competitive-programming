// https://dmoj.ca/problem/dmopc13c3p3

#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

bool vis[2000][2000];
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, H;
    cin >> N >> H;
    signed short field[N][N];
    
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            cin >> field[i][j];


    queue<int> rQ;
    queue<int> cQ;
    rQ.push(0);
    cQ.push(0);
    vis[0][0] = true;

    while(!rQ.empty()) {
        int r = rQ.front();
        int c = cQ.front();
        int elev = field[r][c];
        rQ.pop(); cQ.pop();

        if(r == N-1 && c == N-1) {
            cout << "yes" << endl;
            return 0;
        }

        // Right
        if(c < N-1 && abs(field[r][c+1] - elev) <= H && !vis[r][c+1]) {
            rQ.push(r);
            cQ.push(c+1);
            vis[r][c+1] = true;
        }
        
        // Down
        if(r < N-1 && abs(field[r+1][c] - elev) <= H && !vis[r+1][c]) {
            rQ.push(r+1);
            cQ.push(c);
            vis[r+1][c] = true;
        }
    }
    cout << "no" << endl;
}
