// https://dmoj.ca/problem/ccc99s4

#include <bits/stdc++.h>
#pragma GCC optimize "Ofast"

// It's basically scanf but faster
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

using namespace std;
const int MAX_INT = numeric_limits<int>::max();

int main() {
    int N;
    scanf("%i", &N);

    for(int game = 0; game < N; game++) {
        int rows; int cols;
        int pr; int pc;
        int kr; int kc;

        scan(rows); scan(cols);
        scan(pr); scan(pc);
        scan(kr); scan(kc);

        int kdist[rows+1][cols+1];
        for(int i = 1; i < rows+1; i++)
            for(int j = 1; j < cols+1; j++) 
                kdist[i][j] = MAX_INT;

        queue<int> rQ;
        queue<int> cQ;
        rQ.push(kr);
        cQ.push(kc);
        kdist[kr][kc] = 0;

        // BFS
        while(!rQ.empty()) {
            int r = rQ.front();
            int c = cQ.front();
            rQ.pop();
            cQ.pop();

            if(r-2 > 0 && c+1 <= cols && kdist[r-2][c+1]>kdist[r][c]+1) {
                kdist[r-2][c+1] = kdist[r][c] + 1;
                rQ.push(r-2);
                cQ.push(c+1);
            }
            if(r-1 > 0 && c+2 <= cols && kdist[r-1][c+2]>kdist[r][c] + 1) {
                kdist[r-1][c+2] = kdist[r][c] + 1;
                rQ.push(r-1);
                cQ.push(c+2);
            }

            if(r+1 <= rows && c+2 <= cols && kdist[r+1][c+2]>kdist[r][c] + 1) {
                kdist[r+1][c+2] = kdist[r][c] + 1;
                rQ.push(r+1);
                cQ.push(c+2);
            }
            
            if(r+2 <= rows && c+1 <= cols && kdist[r+2][c+1]>kdist[r][c] + 1) {
                kdist[r+2][c+1] = kdist[r][c] + 1;
                rQ.push(r+2);
                cQ.push(c+1);
            }
            if(r+2 <= rows && c-1 > 0 && kdist[r+2][c-1]>kdist[r][c] + 1) {
                kdist[r+2][c-1] = kdist[r][c] + 1;
                rQ.push(r+2);
                cQ.push(c-1);
            }
            if(r+1 <= rows && c-2 > 0 && kdist[r+1][c-2]>kdist[r][c] + 1) {
                kdist[r+1][c-2] = kdist[r][c] + 1;
                rQ.push(r+1);
                cQ.push(c-2);
            }
            if(r-1 > 0 && c-2 > 0 && kdist[r-1][c-2] > kdist[r][c] + 1) {
                kdist[r-1][c-2] = kdist[r][c] + 1;
                rQ.push(r-1);
                cQ.push(c-2);
            }
            if(r-2 > 0 && c-1 > 0 && kdist[r-2][c-1] > kdist[r][c] + 1) {
                kdist[r-2][c-1] = kdist[r][c] + 1;
                rQ.push(r-2);
                cQ.push(c-1);
            }
        }
        
        // Kinda hacky solution but it works ok
        if(pc == kc && kr == pr+1)
            printf("Stalemate in 0 knight move(s).\n"); 
        else {
            int movesToCheckmate = -1;
            int movesToStale = -1;
            for(int j = 1; j < rows-pr; j++) {
                int knightDist = kdist[pr+j][pc];
                int pawnDist = j;
                
                if(knightDist == pawnDist) {
                    movesToCheckmate = knightDist;
                    break;
                }

                // Handle cases where the same square might have to be revisited
                if((pawnDist - knightDist) % 2 == 0 && pawnDist > knightDist) {
                    movesToCheckmate = pawnDist;
                    break;
                }

                if(kdist[pr+j+1][pc] == pawnDist && movesToStale == -1)
                    movesToStale = kdist[pr+j+1][pc];
            }
            if(movesToCheckmate != -1)
                printf("Win in %i knight move(s).\n", movesToCheckmate);
            else if (movesToStale != -1)
                printf("Stalemate in %i knight move(s).\n", movesToStale);
            else 
                printf("Loss in %i knight move(s).\n", rows-pr-1);
        }
    }
}
