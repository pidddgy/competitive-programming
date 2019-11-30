// https://dmoj.ca/problem/nccc6s3

#include <bits/stdc++.h>
#define MAXINT 2147483647
#define watch(x) cout << (#x) << " is " << (x) << endl;
#define endl '\n'
#define ld long double
using namespace std;

bool wind[105][105];
bool vis[105][105][50][50];
int X, Y, N;

struct state {
    int curx;
    int cury;
    int xvel;
    int yvel;
    int elapsed;
    state(int CURX, int CURY, int XVEL, int YVEL, int ELAPSED) {
        curx = CURX;
        cury = CURY;
        xvel = XVEL;
        yvel = YVEL;
        elapsed = ELAPSED;
    }
};

int v(int n) {
    if(n < 0) {
        return n+30;
    } else {
        return n;
    }
}

bool goodpath(int x1, int y1, int x2, int y2) {
    if(x1 == x2 && y1 == y2) return true;
    if(x2 > X || x2 < 0) return false;
    if(y2 > Y || y2 < 0) return false;

    ld m = y1 - y2;
    ld slope = m/((ld)x1 - (ld)x2);
    ld intercept = y1 - ((ld)x1 * slope);

    if(x1 == x2) {
        for(int i = min(y1, y2); i <= max(y1, y2); i++) {
            if(wind[x1][i]) {
                return false;
            }
        }
    } else if (y1 == y2) {
        for(int i = min(x1, x2); i <= max(x1, x2); i++) {
            if(wind[i][y1]) {
                return false;
            }
        }
    } else {
        for(int i = min(x1, x2); i <= max(x1, x2); i++) {
            ld y = i*slope;
            y += intercept;
            int cute = y;
            if(wind[i][cute]) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    cin >> X >> Y >> N;

    int xs, ys, xe, ye;
    cin >> xs >> ys >> xe >> ye;

    while(N--) {
        int x, y;
        cin >> x >> y;
        wind[x][y] = true;
    }

    queue<state> Q;
    Q.push(state(xs, ys, 0, 0, 0));
    vis[xs][ys][0][0] = true;

    int mi = MAXINT;
    while(!Q.empty()) {
        state s = Q.front();
        Q.pop();

        if(s.curx == xe && s.cury == ye && s.xvel == 0 && s.yvel == 0) {
            mi = min(mi, s.elapsed);
        }
    
        // increment x
        if(s.xvel+1 <= 15) {
            if(goodpath(s.curx, s.cury, s.curx+s.xvel+1, s.cury+s.yvel))
            if(!vis[s.curx+s.xvel+1][s.cury+s.yvel][v(s.xvel+1)][v(s.yvel)]) {
                vis[s.curx+s.xvel+1][s.cury+s.yvel][v(s.xvel+1)][v(s.yvel)] = true;
                Q.push(state(s.curx+s.xvel+1, s.cury+s.yvel, s.xvel+1, s.yvel, s.elapsed+1));
            }
        }

        // increment y
        if(s.yvel+1 <= 15) {
            if(goodpath(s.curx, s.cury, s.curx+s.xvel, s.cury+s.yvel+1))
            if(!vis[s.curx+s.xvel][s.cury+s.yvel+1][v(s.xvel)][v(s.yvel+1)]) {
                vis[s.curx+s.xvel][s.cury+s.yvel+1][v(s.xvel)][v(s.yvel+1)] = true;
                Q.push(state(s.curx+s.xvel, s.cury+s.yvel+1, s.xvel, s.yvel+1, s.elapsed+1));
            }
        }

        // decrement x
        if(s.xvel-1 >= -15) {
            if(goodpath(s.curx, s.cury, s.curx+s.xvel-1, s.cury+s.yvel))
            if(!vis[s.curx+s.xvel-1][s.cury+s.yvel][v(s.xvel-1)][v(s.yvel)]) {
                vis[s.curx+s.xvel-1][s.cury+s.yvel][v(s.xvel-1)][v(s.yvel)] = true;
                Q.push(state(s.curx+s.xvel-1, s.cury+s.yvel, s.xvel-1, s.yvel, s.elapsed+1));
            }
        }

        // decrement y
        if(s.yvel-1 >= -15) {
            if(goodpath(s.curx, s.cury, s.curx+s.xvel, s.cury+s.yvel-1))
            if(!vis[s.curx+s.xvel][s.cury+s.yvel-1][v(s.xvel)][v(s.yvel-1)]) {
                vis[s.curx+s.xvel][s.cury+s.yvel-1][v(s.xvel)][v(s.yvel-1)] = true;
                Q.push(state(s.curx+s.xvel, s.cury+s.yvel-1, s.xvel, s.yvel-1, s.elapsed+1));
            }
        }

        // no change
        if(goodpath(s.curx, s.cury, s.curx+s.xvel, s.cury+s.yvel)) {
            if(!vis[s.curx+s.xvel][s.cury+s.yvel][v(s.xvel)][v(s.yvel)]) {
                vis[s.curx+s.xvel][s.cury+s.yvel][v(s.xvel)][v(s.yvel)] = true;
                Q.push(state(s.curx+s.xvel, s.cury+s.yvel, s.xvel, s.yvel, s.elapsed+1));
            }
        }
    }

    if(mi == MAXINT)
        cout << -1 << endl;
    else
        cout << mi << endl;
}

/*
7 7 3
1 1
4 5
2 5
3 4
4 3

-> 6

3 3 2
2 1
1 2
1 1
2 2

-> 8
*/