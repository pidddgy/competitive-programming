 // https://dmoj.ca/problem/mnyc17p3

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
#define int long long
#define cerr if(false) cerr
const int SEED = 131;
const int MOD = 1000000007;
const int MAXL = 1000005;

int ha[MAXL];
int hb[MAXL];
int smod[MAXL];

int getH(int l, int r, string which) {
    if(which == "ha") {
        return (ha[r] - (ha[l-1] * smod[r-l+1]));        
    } else {
        return (hb[r] - (hb[l-1] * smod[r-l+1]));
    } 
}

signed main() {
    smod[0] = 1;
    for(int i = 1; i < MAXL; i++) {
        smod[i] = (smod[i-1]*SEED);
    }

    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    string a, b;
    cin >> a >> b;

    for(int i = 1; i <= a.size(); i++) {
        ha[i] = ha[i-1]*SEED + a[i-1];
        // ha[i] %= MOD;
        // watch(i)
        // watch(ha[i])
    }

    for(int i = 1; i <= b.size(); i++) {
        hb[i] = hb[i-1]*SEED + b[i-1];
        // hb[i] %= MOD;
    }

    // watch(getH(1, 5, "ha"))
    watch(getH(2, 5, "ha"))
    watch(getH(1, 4, "hb"))
    // watch(getH(0, 0, "hb"))

    int best = 0;
    for(int i = 1; i <= min(a.size(), b.size()); i++) {
        watch(i)
        watch(a.size()-i+1)
        watch(a.size())
        watch(getH(a.size()-i+1, a.size(), "ha"))
        watch(getH(1, i, "hb"))
        cerr << endl;

        if(getH(a.size()-i+1, a.size(), "ha") == getH(1, i, "hb")) {
            best = i;
        }
    }

    // watch(best)
    cout << a;
    for(int i = best; i < b.size(); i++) {
        cout << b[i];
    }
    cout << endl;





}