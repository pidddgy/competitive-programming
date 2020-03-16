// https://codeforces.com/contest/489/problem/C

#include <bits/stdc++.h>
#define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
int g[200];
int l[200];

int main() {
    int m, s;
    cin >> m >> s;

    if(s == 0) {
        if(m == 1) {
            cout << "0 0" << endl;
        } else {
            cout << "-1 -1" << endl;
        }

        return 0;
    }

    int lsum = 1;
    l[1]++;

    for(int i = m; i >= 1; i--) {
        while(l[i] < 9 and lsum < s) {
            l[i]++;
            lsum++;
        }
    }
    
    int gsum = 1;
    g[1]++;

    for(int i = 1; i <= m; i++) {
        while(g[i] < 9 and gsum < s) {
            g[i]++;
            gsum++;
        }
    }

    if((lsum != s) or (gsum != s)) {
        cerr << "doot" << endl;
        watch(lsum)
        watch(gsum)
        cout << -1 << " " << -1 << endl;
        return 0;
    }

    for(int i = 1; i <= m; i++) {
        cout << l[i];
    }
    cout << " ";
    for(int i = 1; i <= m; i++) {
        cout << g[i];
    }

    cout << endl;



    
}