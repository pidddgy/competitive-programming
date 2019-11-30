// https://dmoj.ca/problem/dmopc14c1p5

#include <bits/stdc++.h>
#define MAXINT 2147483647
#define watch(x) cout << (#x) << " is " << (x) << endl;
using namespace std;
int R, C;
bool valid(int a, int b) {
    if(a < 0) return false;
    if(a >= R) return false;

    if(b < 0) return false;
    if(b >= C) return false;

    return true;
}

int main() {

    cin >> R >> C;

    int sr, sc, er, ec;
    cin >> sr >> sc >> er >> ec;

    char a[R][C];
    for(int i = 0; i < R; i++)
        for(int j = 0; j < C; j++)
            cin >> a[i][j];
    

    queue<int> rQ;
    queue<int> cQ;
    int dist[R][C];
    for(int i = 0; i < R; i++)
        for(int j = 0; j < C; j++)
            dist[i][j] = MAXINT;
    
    rQ.push(sr);
    cQ.push(sc);
    dist[sr][sc] = 0;

    while(!cQ.empty()) {
        int r = rQ.front(); rQ.pop();
        int c = cQ.front(); cQ.pop();

        if(valid(r+1, c)) {
            if(dist[r+1][c] == MAXINT and a[r+1][c] != 'X') {
                rQ.push(r+1);
                cQ.push(c);
                dist[r+1][c] = dist[r][c]+1;
            }
        }

        if(valid(r-1, c)) {
            if(dist[r-1][c] == MAXINT and a[r-1][c] != 'X') {
                rQ.push(r-1);
                cQ.push(c);
                dist[r-1][c] = dist[r][c]+1;
            }
        }

        if(valid(r, c+1)) {
            if(dist[r][c+1] == MAXINT and a[r][c+1] != 'X') {
                rQ.push(r);
                cQ.push(c+1);
                dist[r][c+1] = dist[r][c] + 1;
            }
        }

        if(valid(r, c-1)) {
            if(dist[r][c-1] == MAXINT and a[r][c-1] != 'X') {
                rQ.push(r);
                cQ.push(c-1);
                dist[r][c-1] = dist[r][c] + 1;
            }
        }
    }

    int o = dist[er][ec];
    int s = 2147483647;

 
    int T; cin >> T;
    for(int i = 0; i < T; i++) {
        int ar, ac;
        cin >> ar >> ac;
        
        s = min(s, dist[ar][ac]);
    }

    // watch(o);
    // watch(s);

    cout << o-s << endl;
}