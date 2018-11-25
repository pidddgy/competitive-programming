#include <bits/stdc++.h>
#pragma GCC optimize "Ofast"
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
using namespace std;

const int MAX = 999;

int main() {
    int sr; int sc;
    int er; int ec;
      
    scan(sr);
    scan(sc);
    scan(er);
    scan(ec);

    int board[9][9];
    // Fill board with all MAX
    for(int i = 1; i < 9; i++) {
        for(int j = 1; j < 9; j++) {
            board[i][j] = MAX;
        }
    }
    
    queue<int> rQ;
    queue<int> cQ;

    // Start bfs from beginning loc
    board[sr][sc] = 0;
    rQ.push(sr);
    cQ.push(sc);

    while(!rQ.empty()) {
        int r = rQ.front();
        int c = cQ.front();
        rQ.pop();
        cQ.pop();
        if(r == er && c == ec) {
            printf("%i\n", board[r][c]);
            break;
        }
        // Get neighbours but check boundary
        if(r-2 >= 0 && c+1 <= 8 && board[r-2][c+1]>board[r][c]+1) {
            board[r-2][c+1] = board[r][c] + 1;
            rQ.push(r-2);
            cQ.push(c+1);
        }
        if(r-1 >= 0 && c+2 <= 8 && board[r-1][c+2]>board[r][c] + 1) {
            board[r-1][c+2] = board[r][c] + 1;
            rQ.push(r - 1);
            cQ.push(c + 2);
        }

        if(r+1 <= 8 && c+2 <= 8 && board[r+1][c+2]>board[r][c] + 1) {
            board[r+1][c+2] = board[r][c] + 1;
            rQ.push(r+1);
            cQ.push(c+2);
        }
        if(r+2 <= 8 && c+1 <= 8 && board[r+2][c+1]>board[r][c] + 1) {
            board[r+2][c+1] = board[r][c] + 1;
            rQ.push(r+2);
            cQ.push(c+1);
        }
        if(r+2 <= 8 && c-1 >= 0 && board[r+2][c-1]>board[r][c] + 1) {
            board[r+2][c-1] = board[r][c] + 1;
            rQ.push(r+2);
            cQ.push(c-1);
        }

        if(r+1 <= 8 && c-2 >= 0 && board[r+1][c-2]>board[r][c] + 1) {
            board[r+1][c-2] = board[r][c] + 1;
            rQ.push(r+1);
            cQ.push(c-2);
        }

        if(r-1 >= 0 && c-2 >= 0 && board[r-1][c-2] > board[r][c] + 1) {
            board[r-1][c-2] = board[r][c] + 1;
            rQ.push(r - 1);
            cQ.push(c - 2);
        }
        if(r-2 >= 0 && c-1 >= 0 && board[r-2][c-1] > board[r][c] + 1) {
            board[r-2][c-1] = board[r][c] + 1;
            rQ.push(r - 2);
            cQ.push(c - 1);
        }
    }
}   
