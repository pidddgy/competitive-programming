#include <bits/stdc++.h>
#define pii pair<int, int>
#define fi first
#define se second
#define maxc 1000500
#define watch(x) cout << (#x) << " is " << (x) << endl;
using namespace std;
int C[1000500];


int main() {
    int N, K;
    cin >> N >> K;

    unordered_map<int, int> ind;
    unordered_map<int, unordered_map<int, char>> thing;
    unordered_map<int, unordered_map<int, int>> turn;

    string player = "ashley";

    vector<pii> filled; 
    // column -> row
    for(int i = 1; i <= N; i++) {
        int cute;
        cin >> cute;

        ind[cute]++;

        int r = ind[cute];
        int c = cute;
        if(player == "ashley") {
            thing[r][c] = 'a';
            turn[r][c] = i;
            player = "oleg";
        } else {
            thing[r][c] = 'o';
            turn[r][c] = i;
            player = "ashley";
        }

        // cout << "emplacing to " << r << " " << c<<endl;

        filled.emplace_back(r,c);
    }

    int earliest = INT_MAX;
    char won = '?';
    for(pii x: filled) {
        int r = x.fi;
        int c = x.se;
        char pl = thing[r][c];

        // cout << "currently on " << r << " " << c << endl;

        // right
        int rlen = 1;
        int rma = turn[r][c];

        for(int i = 1; i <= K-1; i++) {
            // check if exists
            if(c+i < maxc) {
                if(ind[c+i] >= r) {
                    if(thing[r][c+i] == pl) {
                        // cout << "thing of " << r << " " << c+i << " is " << thing[r][c+i] << endl;
                        rlen++;
                        rma = max(rma, turn[r][c+i]);
                    } else {
                        break;
                    }
                } else {
                    break;
                }
            }


            if(rlen >= K) break;
        }


        // down
        int dlen = 1;
        int dma = turn[r][c];
        
        for(int i = 1; i <= K-1; i++) {
            // check if exists
            if(r-i >= 1) {
                if(thing[r-i][c] == pl) {
                    dlen++;
                    dma = max(dma, turn[r-i][c]);
                } else break;
            }

            if(dlen >= K) break;

        }


        // down right
        int drlen = 1;
        int drma = turn[r][c];
        for(int i = 1; i <= K-1; i++) {
            if(c+i >= 1)
            if(ind[c+i] >= r-i) {
                if(thing[r-i][c+i] == pl) {
                    drlen++;
                    drma = max(drma, turn[r-i][c+i]);
                }
            }

            if(drlen >= K) break;

        }

        // up right
        int urlen = 1;
        int urma = turn[r][c];
        for(int i = 1; i <= K-1; i++) {
            if(c+i <= maxc)
            if(ind[c+i] >= r+i) {
                if(thing[r+i][c+i] == pl) {
                    urlen++;
                    urma = max(urlen, turn[r+i][c+i]);
                }
            }
            if(urlen >= K) break;

        }

        if(rlen >= K) {
            if(rma < earliest) {
                earliest = rma;
                won = pl;

            }
            
        }

        if(dlen >= K) {
             if(dma < earliest) {
                earliest = dma;
                won = pl;

            }
        }

        if(drlen >= K) {
             if(drma < earliest) {
                earliest = drma;
                won = pl;

            }
        }

        if(urlen >= K) {
            if(urma < earliest) {
                earliest = urma;
                won = pl;
            }
        }

        // cout << endl;
    }

    assert(won != '?');
    if(won == 'a') cout << "Asheley ";
    else cout << "Oleg ";
    cout << earliest << endl;

    



    // for(int i = 1; i < 1000500; i++) {
    //     if(grid[i].size()) {
    //         for(char x: grid[i]) {
    //             cout << x << " ";
    //         }
    //         cout << endl;
    //     }
    // }



}