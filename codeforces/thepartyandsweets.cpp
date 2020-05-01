// https://codeforces.com/contest/1158/problem/A

#include <bits/stdc++.h>
using namespace std;
int main() {
    #define int long long
    int n, m;
    cin >> n >> m;

    int b[n+1];
    int g[m+1];

    int bma = 0;
    int bsma = 0;
    int bsum = 0;
    for(int i = 1; i <= n; i++) {
        cin >> b[i];

        if(b[i] > bma) {
            bsma = bma;
            bma = b[i];
        } else if(b[i] > bsma) {
            bsma = b[i];
        }

        bsum += b[i];
    }

    int gmi = INT_MAX;
    int gsum = 0;
    for(int i = 1; i <= m; i++) {
        cin >> g[i];
        gsum += g[i];
        gmi = min(gmi, g[i]);
    }

    if(bma > gmi) {
        cout << -1 << endl;
        return 0;
    }

    if(bma != gmi) {
        int ans = (bsum*m) + (gsum - (bma*(m-1))) - bsma;
        cout << ans << endl;
    } else {
        int ans = (bsum*m) + (gsum - (bma*m));
        cout << ans << endl;
    }

}