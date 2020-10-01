// https://dmoj.ca/problem/usaco19decbronze2    

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    string s;
    cin >> s;

    s = "."+s;

    for(int i = 1; i <= N; i++) {
        // watch(i)
        map<string, bool> seen;
        bool ok = true;
        for(int j = 1; j <= N-i+1; j++) {
            string x;
            for(int k = j; k <= j+i-1; k++) {
                x += s[k];
            }
            // cerr << "generated " << x << endl;
            if(seen[x]) ok = false;

            seen[x] = true;
        }
        if(ok) {
            cout << i << endl;
            return 0;
        }
    }
}
