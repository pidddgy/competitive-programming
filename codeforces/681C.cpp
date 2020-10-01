// https://codeforces.com/problemset/problem/681/C

#include <bits/stdc++.h>
using namespace std;
#define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define int long long
#define pss pair<string, string>
#define fi first
#define se second
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int m;
    cin >> m;

    vector<pss> ans;
    multiset<int> S;
    for(int i = 1; i <= m; i++) {
        string a, b;
        cin >> a;

        if(a != "removeMin") cin >> b;


        if(a == "insert") {
            ans.emplace_back(a, b);
            S.emplace(stoi(b));
        } else if(a == "getMin") {
            watch(*S.begin())
            int x = stoi(b);
            if(S.find(x) == S.end()) {
                S.emplace(x);
                ans.emplace_back("insert", to_string(x));
            }

            while(*S.begin() != x) {
                S.erase(S.begin());
                ans.emplace_back("removeMin", "");
            }

            ans.emplace_back(a, b);
        } else if(a == "removeMin") {
            if(S.size() == 0) {
                ans.emplace_back("insert", "1");
                S.emplace(1);
            }
            S.erase(S.begin());

            ans.emplace_back("removeMin", "");
        }
    }

    cout << ans.size() << endl;
    for(pss x: ans) {
        cout << x.fi << " " << x.se << endl;
    }
}
