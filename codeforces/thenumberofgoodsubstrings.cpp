// https://codeforces.com/contest/1217/problem/C

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
int main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while(T--) {
        string s;
        cin >> s;

        int nxt[s.size()];
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '1') {
                nxt[i] = i;
            } else if(i == 0) {
                nxt[i] = -1;
            } else {
                nxt[i] = nxt[i-1];
            }
        }

        int ans = 0;
        for(int r = 0; r < s.size(); r++) {
            int sum = 0;
            for(int l = r; l >= 0 and (r-l) < 20; l--) {
                if(s[l] == '1') {
                    sum += 1 << (r-l);

                    int n;
                    if(l == 0) {
                        n = -1;
                    } else {
                        n = nxt[l-1];
                    }

                    if(sum <= r - n) {
                        cerr << "adding for " << l << "," << r << endl;
                        watch(sum)
                        ans++;
                    }
                }
            }
        }

        cout << ans << endl;


    }
}