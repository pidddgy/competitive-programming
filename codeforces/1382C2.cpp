// https://codeforces.com/contest/1382/problem/C2

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n'
#define int long long
#define all(x) (x).begin(), (x).end()

string flip(string str, int ind) {
    if(ind == 0) return str;
    for(int i = 0; i < ind; i++) {
        if(str[i] == '1') str[i] = '0';
        else str[i] = '1';
    }
    reverse(str.begin(), str.begin()+ind);

    return str;
}

vector<int> path(string s, string t) {
    for(int i = 0; i <= s.size(); i++) {
        for(int j = 0; j <= s.size(); j++) {
            for(int k = 0; k <= s.size(); k++) {
                for(int l = 0; l <= s.size(); l++) {
                    string cpy = s;
                    cerr << i << " " << j << " " << k << " " << l << endl;
                
                    cpy = flip(cpy, i);
                    // watch(cpy)
                    cpy = flip(cpy, j);
                    // watch(cpy)
                    cpy = flip(cpy, k);
                    // watch(cpy)

                    cpy = flip(cpy, l);
                    watch(cpy)

                    if(cpy == t) {
                        // cerr << "found with " << i << " " << j << " " << k << " " << l << endl;
                        vector<int> res;
                        for(int ree: vector<int>({i, j, k, l})) {
                            if(ree != 0) {
                                res.emplace_back(ree);
                            }
                        }

                        return res;
                    }
                }
            }
        }
    }
    watch(s)
    watch(t)
    assert(false);
}

set<string> strings;

void getStrings(string cur = "") {
    strings.emplace(cur);
    if(cur.size() == 3) {
        strings.emplace(cur);
        return;
    } else {
        getStrings(cur+"1");
        getStrings(cur+"0");
    }
}


void solve() {
    int n;
    cin >> n;

    string a, b;
    cin >> a >> b;

    vector<int> ans;

    for(int i = 0; i < n; i += 3) {
        string s, t;
        for(int j = 2; j >= 0; j--) {
            if(i+j <= n) {
                s += a[i+j];
                t += b[i+j];
            }
        }

        ans.emplace_back(min(n, i+2));
        for(int x: path(s, t)) {
            ans.emplace_back(x);
        }
        ans.emplace_back(min(n, i+2));
    }

    string cpy = a;
    for(int x: ans) {
        cpy = flip(cpy, x);
    }
    watch(cpy)
    watch(b)
    cout << ans.size() << " ";
    for(int x: ans) {
        cout << x << " ";
    }
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    // getStrings();
    for(int x: path("10", "01")) {
        cerr << x << " ";
    }
    cerr << endl;

    int t;
    cin >> t;

    while(t--) {
        solve();
    }
}
