// https://codeforces.com/contest/154/problem/B

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define cerr if(false) cerr

const int maxn = 100050;

set<int> facs[maxn];
bool on[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for(int q = 1; q <= m; q++) {
        char x;
        int i;

        cin >> x >> i;

        if(x == '+') {
            if(on[i]) {
                cout << "Already on" << endl;
                continue;
            }
            int conf = -1;

            cerr << "trying to add " << i << endl;
            for(int j = 1; j <= min(i, (int)sqrt(i)+2); j++) {
                if(i%j == 0) {
                    cerr << "checking " << j << " and " << i/j << endl;
                    if(facs[j].size() and j != 1) {
                        conf = *facs[j].begin();
                    } else if(facs[i/j].size() and i/j != 1) {
                        conf = *facs[i/j].begin();
                    }
                }
            }

            if(conf == -1) {
                cout << "Success" << endl;
                on[i] = true;
                for(int j = 1; j <= min(i, (int)sqrt(i)+2); j++) {
                    if(i%j == 0) {
                        cerr << "emplacing to " << j << " and " << i/j << endl;
                        facs[j].emplace(i);
                        facs[i/j].emplace(i);
                    }
                }
            } else {
                cout << "Conflict with " << conf << endl;
            }
        } else {
            if(!on[i]) {
                cout << "Already off" << endl;
            } else {
                cout << "Success" << endl;
                on[i] = false;
            }

            for(int j = 1; j <= min(i, (int)sqrt(i)+2); j++) {
                if(i%j == 0) {
                    if(facs[j].count(i)) {
                        facs[j].erase(i);
                    }
                    
                    if(facs[i/j].count(i)) {
                        facs[i/j].erase(i);
                    }
                }
            }
        }
        cerr << endl;
    }
}