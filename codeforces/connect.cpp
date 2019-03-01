// http://codeforces.com/contest/1130/problem/C

#include <bits/stdc++.h>
#define pii pair<int, int>
#define row first
#define col second
#define mp make_pair
using namespace std;

vector<pii> s;
vector<pii> d;
int N;

void bfs(int R, int C, vector<vector<char>> A, char w) {
    queue<int> rQ;
    queue<int> cQ;
    bool vis[N+1][N+1];
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            vis[i][j] = false;
        }
    }

    rQ.push(R);
    cQ.push(C);
    vis[R][C] = true;

    while(!rQ.empty()) {
        int r = rQ.front();
        int c = cQ.front();

        if(w == 'S')
            s.emplace_back(mp(r, c));
        else if (w == 'D')
            d.emplace_back(mp(r,c));

        rQ.pop(); cQ.pop();

        // up
        if(r-1 >= 1)
            if(!vis[r-1][c] && A[r-1][c] != 'W') {
                rQ.push(r-1);
                cQ.push(c);
                vis[r-1][c] = true;
            }

        // right
        if(c+1 <= N) 
            if(!vis[r][c+1] && A[r][c+1] != 'W') {
                rQ.push(r);
                cQ.push(c+1);
                vis[r][c+1] = true;
            }
        
        // down
        if(r+1 <= N) {
            if(!vis[r+1][c] && A[r+1][c] != 'W') {
                rQ.push(r+1);
                cQ.push(c);
                vis[r+1][c] = true;
            }
        }

        // left
        if(c-1 >= 1) {
            if(!vis[r][c-1] && A[r][c-1] != 'W') {
                rQ.push(r);
                cQ.push(c-1);
                vis[r][c-1] = true;
            }
        }
    }
}


int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;

    vector<vector<char>> A(N+1);
    for(int i = 1; i <= N; i++) {
        A[i].emplace_back('.');
        for(int j = 1; j <= N; j++) {
            char a;
            cin >> a;
            if(a == '0') A[i].emplace_back('L');
            else if(a == '1') A[i].emplace_back('W');
        }
    }

    bfs(r1, c1, A, 'S');
    bfs(r2, c2, A, 'D');

    int t = 2147483647;
    for(auto i: s) {
        if(i.row == r2 && i.col == c2) {
            cout << 0 << endl;
            return 0;
        }

        for(auto j: d) {
            int c = pow(abs(i.row - j.row), 2) + pow(abs(i.col - j.col), 2);
            t = min(t, c);
        }
    }

    cout << t << endl;
}
