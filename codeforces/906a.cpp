// https://codeforces.com/contest/906/problem/A

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
#define int long long
// #define cerr if(false) cerr
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    set<char> S;
    for(int i = 0; i < 26; i++) {
        S.emplace('a'+i);
    }

    int ans = 0;
    for(int i = 1; i <= n-1; i++) {
        string type, w;
        cin >> type >> w;

        if((S.size() == 1) and (type != ".")) {
            ans++;
        }

        set<char> wS;
        for(char x: w) {
            wS.emplace(x);
        }

        if(type == "!") {
            set<char> inter;
            set_intersection(S.begin(), S.end(), wS.begin(), wS.end(), inserter(inter, inter.begin()));
            
            S.clear();
            S.clear();
            for(char x: inter) {
                S.emplace(x);
            }
        } else {
            set<char> diff;
            set_difference(S.begin(), S.end(), wS.begin(), wS.end(), inserter(diff, diff.begin()));
            
            S.clear();
            for(char x: diff) {
                S.emplace(x);
            }
        }

        // for(char x: S) {
        //     cerr << x << " ";
        // }
        // cerr << endl;
    }

    cout << ans << endl;
}