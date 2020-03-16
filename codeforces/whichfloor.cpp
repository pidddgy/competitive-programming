// https://codeforces.com/contest/858/problem/B 

#include <bits/stdc++.h>
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;

    // map of flat->floor
    unordered_map<int, int> ffm;
    // for(int i = 1; i <= 200; i++) {
    //     ffm[i] = -1; // -1 = unknown
    // }

    for(int i = 1; i <= m; i++) {
        int k, f;
        cin >> k >> f;

        ffm[k] = f;
    }

    set<int> poss;
    // i = flats on each floor
    for(int i = 1; i <= 105; i++) {
        bool good = true;
        for(pii x: ffm) {
            if(((x.fi + i-1) / i) != x.se) {
                good = false; 
            }
        }

        if(good) {
            poss.emplace((n + i-1) / i);
        }
    }

    if(poss.size() > 1) {
        cout << -1 << endl;
    } else {
        cout << *poss.begin() << endl;
    }
}