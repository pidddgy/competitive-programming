// https://codeforces.com/contest/761/problem/C

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    // min cost to get to x
    int dig[n+1];
    int lc[n+1];
    int symb[n+1];

    for(int i = 1; i <= n; i++) {
        dig[i] = lc[i] = symb[i] = INT_MAX;
    }

    for(int i = 1; i <= n; i++) {
        string s;
        cin >> s;

        int mdig = INT_MAX;
        int msymb = INT_MAX;
        int mlc = INT_MAX;
        for(int i = 0; i < m; i++) {
            if(isdigit(s[i])) {
                mdig = min(mdig, i);
            } else if(s[i] == '#' or s[i] == '*' or s[i] == '&') {
                msymb = min(msymb, i);
            } else if(islower(s[i])) {
                mlc = min(mlc, i);
            }
        }

        for(int i = m-1; i >= 0; i--) {
            if(isdigit(s[i])) {
                mdig = min(mdig, m-i);
            } else if(s[i] == '#' or s[i] == '*' or s[i] == '&') {
                msymb = min(msymb, m-i);
            } else if(islower(s[i])) {
                mlc = min(mlc, m-i);
            }
        }

        dig[i] = mdig;
        symb[i] = msymb;
        lc[i] = mlc;
    }

    int ans = INT_MAX;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            for(int k = 1; k <= n; k++) {
                if(i == j or j == k or i == k) continue;

                if(dig[i] == INT_MAX or symb[j] == INT_MAX or lc[k] == INT_MAX) continue;

                ans = min(ans, dig[i]+symb[j]+lc[k]);
            }
        }
    }

    cout << ans << endl;
}