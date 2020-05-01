// https://codeforces.com/contest/1243/problem/B2

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
#define pii pair<int, int>
#define fi first
#define cerr if(false) cerr
#define se second
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int k;
    cin >> k;

    while(k--) {
        int n;
        cin >> n;

        string s, t;
        cin >> s >> t;

        s = "."+s;
        t = "."+t;
        
        vector<pii> ans;
        bool no = false;
        for(int i = 1; i <= n; i++) {
            if(t[i] != s[i]) {
                cerr << i << " not eq" << endl;
                bool found = false;
                for(int j = i+1; j <= n; j++) {
                    if(s[j] == s[i]) {
                        ans.emplace_back(j, i);
                        swap(s[j], t[i]);
                        found = true;
                        break;
                    }
                }

                if(!found) {
                    for(int j = i+1; j <= n; j++) {
                        watch(t[j])
                        if(t[j] == s[i]) {
                            cerr << "using " << j << endl;
                            ans.emplace_back(i+1, j);
                            swap(s[i+1], t[j]);
                            ans.emplace_back(i+1, i);
                            swap(s[i+1], t[i]);
                            found = true;
                            cerr << s << endl;
                            cerr << t << endl;
                            break;
                        }
                    }
                }

                if(!found) {
                    cout << "No" << endl;
                    cerr << s << endl;
                    cerr << t << endl;
                    cerr << "failed on " << i << endl;
                    no = true;
                    break;
                }

                cerr << s << endl;
                cerr << t << endl;
            }
        }

        if(!no) {
            cout << "Yes" << endl;
            cout << ans.size() << endl;
            for(pii x: ans) {
                cout << x.fi << " " << x.se << endl;
            }
        }
    }
}