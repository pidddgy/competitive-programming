// https://codeforces.com/contest/1209/problem/C

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'

int color[200500];
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        string s;
        cin >> s;

        s = "."+s;

        bool found = false;
        for(char x: string("1234567890")) {
            vector<int> one;
            vector<int> two;
            int color[n+1];
            bool seen = false;
            for(int i = 1; i <= n; i++) {
                if(s[i] < x) {
                    one.emplace_back(s[i]-'0');
                    color[i] = 1;
                } else if(s[i] > x) {
                    seen = true;
                    two.emplace_back(s[i]-'0');
                    color[i] = 2;
                } else if(s[i] == x) {
                    if(seen) {
                        one.emplace_back(s[i]-'0');
                        color[i] = 1;
                    } else {
                        two.emplace_back(s[i]-'0');
                        color[i] = 2;
                    }
                }
            }

            if(is_sorted(one.begin(), one.end()) and is_sorted(two.begin(), two.end())) {
                found = true;
                for(int i = 1; i <= n; i++) {
                    cout << color[i];
                }
                cout << endl;
            }

            if(found) break;
        }

        if(!found) {
            cout << "-" << endl;
        }
    }
}