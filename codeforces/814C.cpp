// https://codeforces.com/contest/814/problem/C

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
#define cerr if(false) cerr

const int maxn = 1700;

int psa[30][maxn];

map<int, map<char, int>> memo;


signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    string s;
    cin >> s;

    s = "."+s;

    for(int i = 1; i <= n; i++) {
        psa[s[i]-'a'][i]++;
    }

    for(char x: string("abcdefghijklmnopqrstuvwxyz")) {
        for(int i = 1; i <= n; i++) {
            psa[x-'a'][i] += psa[x-'a'][i-1];
        }
    }

    for(int i = 1; i <= n; i++) {
        cerr << psa['o'-'a'][i] << " ";
    }
    cerr << endl;

    int q;
    cin >> q;

    while(q--) {
        int m;
        char c;
        cin >> m >> c;

        if(memo[m].find(c) != memo[m].end()) {
            cout << memo[m][c] << endl;
            continue;
        }

        int l = 1;
        int r = 1;

        int ma = 0;
        int cur = s[1]==m;

        while(l <= n) {
            cerr << "currently on " << l << "," << r << endl;
            int rng = r-l+1;
            
            while((rng+1 - (psa[c-'a'][r+1] - psa[c-'a'][l-1])) <= m and r <= n) {
                watch(rng+1)
                watch(psa[c-'a'][r+1] - psa[c-'a'][l-1])
                r++;
                rng = r-l+1;
            }

            cerr << "using " << l << "," << r << endl;
            ma = max(ma, r-l+1);
            l++;
            r++;
        }

        memo[m][c] = ma;
        cout << ma << endl;
    }
}