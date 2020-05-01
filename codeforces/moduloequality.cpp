// https://codeforces.com/contest/1269/problem/B

#include <bits/stdc++.h>
using namespace std;
// #define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define int long long
#define pii pair<int, int>
#define fi first
#define se second

// how much to increase to make a == b mod m
int f(int a, int b, int m) {
    if(a > b) {
        return (b+m) - a;
    } else {
        return b-a;
    }
}

signed main() {
    // cerr << f(0, 1, 2) << endl;
    srand(time(0));
    clock_t z = clock();

    int n, m;
    cin >> n >> m;

    int asum = 0;
    int a[n+1];
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        asum += a[i];
    }

    int bsum = 0;
    int b[n+1];
    for(int i = 1; i <= n; i++) {
        cin >> b[i];
        bsum += b[i];
        b[i] %= m;
    }

    sort(b+1, b+n+1);

    int mi = INT_MAX;
    // send help
    for(int shit = 0; shit < 1e5; shit++) {
        int x = (rand()%n)+1;
        int y = (rand()%n)+1;

        int adjust = f(a[x], b[y], m);
        // int adjust = 0;
        // cerr << "adjust is " << adjust << endl;

        int cpy[n+1];
        for(int i = 1; i <= n; i++) cpy[i] = (a[i] + adjust) % m;

        sort(cpy+1, cpy+n+1);

        bool bad = false;
        for(int i = 1; i <= n; i++) {
            if(cpy[i] != b[i]) {
                bad = true;
                break;
            }
        }

        if(!bad) {
            mi = min(mi, adjust);
        }

        if(shit % 3 == 0)
        if(((clock()-z) / (double)CLOCKS_PER_SEC) > 2.5) break;
    }

    cout << mi << endl;
}