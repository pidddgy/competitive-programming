#include <bits/stdc++.h>
#define pii pair<int, int>
#define le first
#define ri second
#define watch(x) cout << (#x) << " is " << (x) << endl;

using namespace std;
int main() {
    int n, q;
    cin >> n >> q;

    int D[n+1]; fill(D, D+n+1, 0); // difference array
    pii P[q+1];

    for(int i = 1; i <= q; i++) {
        int l, r;
        cin >> l >> r;

        P[i].le = l;
        P[i].ri = r;
        D[l] += 1;

        if(r+1 <= n) D[r+1] -= 1;
    }

    // connstruct prefix sum array on array D
    int psa[n+1]; psa[0] = 0;
    psa[1] = D[1];
    for(int i = 2; i <= n; i++) {
        psa[i] = psa[i-1] + D[i];
    }

    int o[n+1]; o[0] = 0; // prefix sum array on how many sections are painted once
    int t[n+1]; t[0] = 0; // prefix sum array on how many sections are painted once or twice
    if(psa[1] == 1) o[1] = 1; else o[1] = 0;
    if(psa[1] >= 1) t[1] = 1; else t[1] = 0;

    // construct both o and t
    for(int i = 2; i <= n; i++) {
        o[i] = o[i-1];
        if(psa[i] == 1) o[i]++;

        t[i] = t[i-1];
        if(psa[i] >= 1) t[i]++;
    }

    int minv = 2147483647; // minimum number of sections that need to be left uncovered
    for(int i = 1; i <= q-1; i++) {
        for(int j = i+1; j <= q; j++) {
            int tot = 0; // sections left uncovered if we exclude painter i and j
            // check if overlap
            if(P[j].le <= P[i].ri) {
                watch(t[P[i].ri] - t[ P[j].le-1 ])
                tot += t[P[i].ri] - t[ P[j].le-1 ];
                cout << "HI" << endl;
                tot += o[P[j].ri] - o[ P[i].ri-1 ];
                tot += o[P[j].le] - o[ P[i].le-1 ];
            } else {
                tot += o[P[i].ri] - o[P[i].le-1];
                tot += o[P[j].ri] - o[P[j].le-1];
                cout << "hi2 " << endl;
            }

            minv = min(tot, minv);
            cout << "min is " << i << " " << j << endl;

        }
    }

    cout << n-minv << "\n";

    for(auto a: D) {
        cout << a << " ";
    }
    cout << endl;

    for(auto a: psa) {
        cout << a << " ";
    }
    cout << endl;

    for(auto a: o) {
        cout << a << " ";
    }
    cout << endl;

    for(auto a: t) {
        cout << a << " ";
    }
    cout << endl;
    
}
