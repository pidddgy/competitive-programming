// https://atcoder.jp/contests/agc033/tasks/agc033_a

#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl;

using namespace std;
bool vis[1004][1004];
int main() {
    int rows, cols;
    cin >> rows >> cols;

    char a[rows+1][cols+1];

    queue<int> rQ;
    queue<int> cQ;
    for(int i = 1; i <= rows; i++) {
        for(int j = 1; j <= cols; j++) {
            cin >> a[i][j];
            if(a[i][j] == '#') {
                rQ.push(i);
                cQ.push(j);
            }
        }
    }

    int ans = 0;
    while(!rQ.empty()) {
        int r = rQ.front();
        int c = cQ.front();
        watch(r)
        watch(c)
        
        rQ.pop(); cQ.pop();
        bool use = false;
        
        // top
        if(r-1>=1) {
            if(a[r-1][c] != '#') {
                a[r-1][c] = '#';
                rQ.push(r-1);
                cQ.push(c);
                use = true;
            }
        } 

        // right
        if(c+1<=cols) {
            if(a[r][c+1] != '#') {
                a[r][c+1] = '#';
                rQ.push(r);
                cQ.push(c+1);
                use = true;
            }
        } 

        //down
        if(r+1<=rows) {
            if(a[r+1][c] != '#') {
                a[r+1][c] = '#';
                rQ.push(r+1);
                cQ.push(c);
                use = true;

            }
        } 

        //left
        if(c-1>=1) {
            if(a[r][c-1] != '#') {
                a[r][c-1] = '#';
                rQ.push(r);
                cQ.push(c-1);
                use = true;
            }
        } 
        if(use) ans++;
    }
    
    cout << ans << endl;



    
}