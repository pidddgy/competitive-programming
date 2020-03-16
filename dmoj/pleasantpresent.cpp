// https://dmoj.ca/problem/dmopc19c4p2

#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl;

#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

bool grid[20][20];
pii curpos;
pii endpos;
pii startthingy;
pii endthingy;
int cost = 0;
int N;

// a, b = empty square and x, y == magnet
int dist(int a, int b, int x, int y) {
    queue<int> rQ;
    queue<int> cQ;
    int dist[20][20];
    for(int i = 0; i < 20; i++)
        for(int j = 0; j < 20; j++)
            dist[i][j] = INT_MAX;
    
    dist[a][b] = 0;
    
    rQ.push(a);
    cQ.push(b);

    while(!rQ.empty()) {
        int R = rQ.front(); rQ.pop();
        int C = cQ.front(); cQ.pop();

        // cout << "currently on " << R << " " << C << endl;
        // cout << grid[R-1][C] << endl;

        // we can't go across empty squares as the marble square
        // has to be empty at all times
        if(R+1 <= N and dist[R+1][C] > dist[R][C]+1 and !grid[R+1][C]) {
            rQ.push(R+1);
            cQ.push(C);

            dist[R+1][C] = dist[R][C]+1;
        }

        if(C+1 <= N and dist[R][C+1] > dist[R][C]+1 and !grid[R][C+1]) {
            rQ.push(R);
            cQ.push(C+1);

            dist[R][C+1] = dist[R][C]+1;
        }

        if(R-1 >= 1 and dist[R-1][C] > dist[R][C]+1 and !grid[R-1][C]) {
            // cout << "pushing up" << endl;
            rQ.push(R-1);
            cQ.push(C);

            dist[R-1][C] = dist[R][C]+1;
        }
        
        if(C-1 >= 1 and dist[R][C-1] > dist[R][C]+1 and !grid[R][C-1]) {
            rQ.push(R);
            cQ.push(C-1);

            dist[R][C-1] = dist[R][C]+1;
        }
    }

    assert(dist[x][y] != INT_MAX);
    return dist[x][y];
}
int main() {
    int rs, cs, re, ce;
    cin >> N >> rs >> cs >> re >> ce;

    curpos = {rs, cs};
    endpos = {re, ce};

    // cout << "curpos is " << endl;
    // cout << curpos.fi << " " << curpos.se << endl;

    startthingy = curpos;
    endthingy = endpos;

    if(curpos == endpos) {
        cout << 0 << endl;
        return 0;
    }
    int e1, e2;
    cin >> e1 >> e2;
    pii emp1 = {e1, e2};

    int cute, cutee;
    cin >> cute >> cutee;
    pii emp2 = {cute, cutee};

    grid[emp1.fi][emp1.se] = true;
    grid[emp2.fi][emp2.se] = true;

    string nonmarbleemp;
    if(curpos == emp1) {
        nonmarbleemp = "emp2";
    } else {
        nonmarbleemp = "emp1";
    }

    // only want to move in two directions
    vector<string> move;

    if(curpos.fi < endpos.fi) {
        move.emplace_back("down");
    }

    if(curpos.fi > endpos.fi) {
        // cout << curpos.fi << " " << endpos.fi << endl;
        // cout << "emplacing up" << endl;
        move.emplace_back("up");
    }

    if(curpos.se > endpos.se) {
        move.emplace_back("left");
    }

    if(curpos.se < endpos.se) {
        move.emplace_back("right");
    }

    // assert(move.size() <= 2);
    // assert(move.size() >= 1);
    int incurred = 0;
    while(!(curpos.fi == endpos.fi and curpos.se == endpos.se)) {
        int mi = INT_MAX;
        string dir = "cute";
        pii moveToSquare;
        pii oldshit;
        pii othershit;
        for(string m: move) { 
            // watch(m)

            pii moveSquare;
            if(nonmarbleemp == "emp1") {
                moveSquare = emp1;
            } else {
                moveSquare = emp2;
            }

            // cout << moveSquare.fi << " " << moveSquare.se << endl;
            pii newLoc = curpos;
            if(m == "down") {
                newLoc.fi++;
            }

            if(m == "up") {
                newLoc.fi--;
            }

            if(m == "right") {
                newLoc.se++;
            }

            if(m == "left") {
                newLoc.se--;
            }

            // cout << "newloc is " << newLoc.fi << "," << newLoc.se << endl;

            if(!(newLoc.fi >= min(startthingy.fi, endthingy.fi) and newLoc.fi <= max(startthingy.fi, endthingy.fi))) {
                continue;
            }

            if(!(newLoc.se >= min(startthingy.se, endthingy.se) and newLoc.se <= max(startthingy.se, endthingy.se))) {
                continue;
            }


            int dis = dist(moveSquare.fi, moveSquare.se, newLoc.fi, newLoc.se)+1;
            // cout << "distance from " << moveSquare.fi << " " << moveSquare.se << " to " << newLoc.fi << " " << newLoc.se << " is " << dis << endl;

            if(dis <= mi) {
                mi = dis;
                dir = m;
                moveToSquare = newLoc;
                oldshit = moveSquare;
                othershit = curpos;
            }
        }


        swap(curpos, moveToSquare);
        grid[oldshit.fi][oldshit.se] = false;
        grid[moveToSquare.fi][moveToSquare.se] = true;
        grid[curpos.fi][curpos.se] = true;

        // cout << "moved " << dir << endl;
        // cout << "cost is " << mi << endl;

    

        incurred += mi;

        // cout << endl;

        if(nonmarbleemp == "emp1") {
            nonmarbleemp = "emp2";
            emp1 = curpos;
            emp2 = moveToSquare;
        } else {
            nonmarbleemp = "emp1";
            emp1 = moveToSquare;
            emp2 = curpos;
        }

        assert(dir != "cute");
    }
    
    assert(incurred > 0);

    curpos = startthingy;
    endpos = endthingy;
    int incurred2 = 0;

    for(int i = 0; i < 20; i++) {
        for(int j = 0; j < 20; j++) {
            grid[i][j] = false;
        } 
    }
    emp1 = {e1, e2};
    emp2 = {cute, cutee};

    grid[emp1.fi][emp1.se] = true;
    grid[emp2.fi][emp2.se] = true;

    if(curpos == emp1) {
        nonmarbleemp = "emp2";
    } else {
        nonmarbleemp = "emp1";
    }

    while(!(curpos.fi == endpos.fi and curpos.se == endpos.se)) {
        int mi = INT_MAX;
        string dir = "cute";
        pii moveToSquare;
        pii oldshit;
        pii othershit;
        for(string m: move) { 
            // watch(m)

            pii moveSquare;
            if(nonmarbleemp == "emp1") {
                moveSquare = emp1;
            } else {
                moveSquare = emp2;
            }

            // cout << moveSquare.fi << " " << moveSquare.se << endl;
            pii newLoc = curpos;
            if(m == "down") {
                newLoc.fi++;
            }

            if(m == "up") {
                newLoc.fi--;
            }

            if(m == "right") {
                newLoc.se++;
            }

            if(m == "left") {
                newLoc.se--;
            }

            // cout << "newloc is " << newLoc.fi << "," << newLoc.se << endl;

            if(!(newLoc.fi >= min(startthingy.fi, endthingy.fi) and newLoc.fi <= max(startthingy.fi, endthingy.fi))) {
                continue;
            }

            if(!(newLoc.se >= min(startthingy.se, endthingy.se) and newLoc.se <= max(startthingy.se, endthingy.se))) {
                continue;
            }


            int dis = dist(moveSquare.fi, moveSquare.se, newLoc.fi, newLoc.se)+1;
            // cout << "distance from " << moveSquare.fi << " " << moveSquare.se << " to " << newLoc.fi << " " << newLoc.se << " is " << dis << endl;

            if(dis < mi) {
                mi = dis;
                dir = m;
                moveToSquare = newLoc;
                oldshit = moveSquare;
                othershit = curpos;
            }
        }


        swap(curpos, moveToSquare);
        grid[oldshit.fi][oldshit.se] = false;
        grid[moveToSquare.fi][moveToSquare.se] = true;
        grid[curpos.fi][curpos.se] = true;

        // cout << "moved " << dir << endl;
        // cout << "cost is " << mi << endl;

    

        incurred2 += mi;

        // cout << endl;

        if(nonmarbleemp == "emp1") {
            nonmarbleemp = "emp2";
            emp1 = curpos;
            emp2 = moveToSquare;
        } else {
            nonmarbleemp = "emp1";
            emp1 = moveToSquare;
            emp2 = curpos;
        }

        assert(dir != "cute");
    }


    cout << min(incurred, incurred2) << endl;




    
    
}