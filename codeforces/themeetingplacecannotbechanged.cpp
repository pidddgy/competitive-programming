// https://codeforces.com/contest/780/problem/B

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define ld long double
using namespace std;
int main() {
    int n;
    cin >> n;

    int x[n+1];
    int xma = 0;
    for(int i = 1; i <= n; i++) {
        cin >> x[i];
        xma = max(xma, x[i]);
    }

    int v[n+1];
    for(int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    ld eps = 1e-10;
    ld l = 1;
    ld r = xma;

    int cnt = 0;
    while(r - l > eps) {
        ld m1 = l + ((r-l)/3);
        ld m2 = r - ((r-l)/3);
        
        cnt++;

        ld f1 = 0;

        for(int i = 1; i <= n; i++) {
            f1 = max(f1, abs(x[i]-m1)/v[i]);
        }

        ld f2 = 0;

        for(int i = 1; i <= n; i++) {
            f2 = max(f2, abs(x[i]-m2)/v[i]);
        }
        if(f1 < f2) {
            r = m2;
        } else {
            l = m1;
        }
    }

    ld ans = 0;
    for(int i = 1; i <= n; i++) {
        ans = max(ans, abs(x[i]-l)/v[i]);
    }
    cout << fixed << setprecision(69) << ans << endl;
}