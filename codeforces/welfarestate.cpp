// https://codeforces.com/contest/1198/problem/B

#include <bits/stdc++.h>
#define maxnq 200500
#define pii pair<int, int>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define fi first
#define se second
using namespace std;

int bestp[maxnq];

int main() {
    for(int i = 0; i < maxnq; i++) bestp[i] = -INT_MAX;
    int N;
    cin >> N;

    int a[N+1];

    for(int i = 1; i <= N; i++) {
        cin >> a[i];
    }

    vector<pii> sets[N+1];

    int Q;
    cin >> Q;

    for(int i = 1; i <= Q; i++) {
        int type;
        cin >> type;

        if(type == 1) {
            int p, x;
            cin >> p >> x;

            sets[p].emplace_back(x, i);
        } else {
            int x;
            cin >> x;

            bestp[i] = x;
        }
    } 

    int best = 0;
    for(int i = Q; i >= 1; i--) {
        bestp[i] = max(bestp[i], bestp[i+1]);
        best = max(best, bestp[i]);
    }

    // for(int i = 1; i <= Q; i++) {
    //     if(bestp[i] != INT_MAX and bestp[i+1] == -INT_MAX) {
    //         cerr << "HIII" << endl;
    //         cerr << i << endl;
    //         bestp[i+1] = bestp[i];
    //     }
    // }

    // for(int i = 1; i <= Q; i++) {
    //     cout << bestp[i] << " ";
    // }
    // cout << endl;

    for(int i = 1; i <= N; i++) {
        int np = 0;
        if(sets[i].empty()) {
            np = a[i];
            cout << max(np, best) << " ";
        } else {
            np = sets[i].back().fi;
            cout << max(np, bestp[sets[i].back().se]) << " ";
        }
    }
    cout << endl;



    


}