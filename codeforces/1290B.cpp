// https://codeforces.com/contest/1290/problem/B

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
string s;
int n, q;

const int maxn = 200500;

int psa[26][maxn];

int query(int chr, int l, int r) {
    return psa[chr][r] - psa[chr][l-1];
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    n = s.size();

    s = "."+s;

    for(int i = 1; i <= n; i++) {
        psa[s[i]-'a'][i]++;
    }

    for(int i = 0; i < 26; i++) {
        for(int j = 1; j <= n; j++) {
            psa[i][j] += psa[i][j-1];
        }
    }

    cin >> q;

    while(q--) {
        int l, r;
        cin >> l >> r;

        string ans = "No";
        int chrs = 0;
        for(int chr = 0; chr < 26; chr++) {
            int freq = query(chr, l, r);
            if(freq) chrs++;
        }

        if(l == r) ans = "Yes";
        if(s[l] != s[r]) ans = "Yes";
        if(chrs >= 3) ans = "Yes";

        cout << ans << endl;
    }
}
