// https://dmoj.ca/problem/dmopc19c5p4

#include <bits/stdc++.h>
#define cerr if(false) cerr
#define watch(x) cout << (#x) << " is " << (x) << endl;
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;
int main() {
    int N, Q;
    cin >> N >> Q;

    int m[N+1];
    for(int i = 1; i <= N; i++) {
        cin >> m[i];
    }

    int v[N+1];
    for(int i = 1; i <= N; i++) {
        cin >> v[i];
    }

    int tm[N+1];
    for(int i = 1; i <= N; i++) {
        tm[i] = m[i];
        if(v[i] == 0) continue;

        else tm[i] += tm[v[i]];
    }



    pii wind[N+1];
    for(int i = 1; i <= N; i++) {
        wind[i] = make_pair(tm[i], i);
    }

    sort(wind+1, wind+N+1);

    for(int i = 1; i <= N; i++) {
        cerr << wind[i].fi << " ";
    }
    cerr << endl;
    for(int i = 1; i <= N; i++) {
        cerr << wind[i].se << " ";
    }
    cerr << endl;

    for(int i = 1; i <= Q; i++) {
        int p, c;
        cin >> p >> c;

        int need;
        if(p >= c) {
            cout << -1 << endl;
            continue;
        } else {
            // cerr << "HIII " << endl;
            need = c-p;
        }

        bool found = false;
        for(int j = 1; j <= N; j++) {
            if(tm[j] >= need) {
                cout << j << endl;
                found = true;
                break;
            }
        }

        if(!found) {
            cerr << "aa" << endl;
            cout << -1 << endl;
        }
        // watch(need)

        // int l = 1;
        // int r = N;
        // int lastgood = -1;
        // while(l <= r) {
        //     int m = (l+r) / 2;

        //     if(wind[m].fi >= need) {
        //         lastgood = m;
        //         r = m-1;
        //     } else {
        //         l = m+1;
        //     }
        // }

        // cout << lastgood << endl;
    }
}