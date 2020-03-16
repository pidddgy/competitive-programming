// https://codeforces.com/contest/1315/problem/C

#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        int a[n+1];
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        int ans[2*n+5];
        for(int i = 1; i <= 2*n; i++) {
            ans[i] = -2;
        }

        set<int> se;
        bool bad = false;

        for(int i = 1; i <= 2*n; i++) {
            se.emplace(i);
        }
        for(int i = 1; i <= n; i++) {
            ans[2*i-1] = a[i];

            if(se.find(a[i]) != se.end()) {
                se.erase(a[i]);
            } else {
                cerr << "HI" << endl;
                bad = true;
            }
        }

        for(int i = 1; i <= n; i++) {
            if(ans[2*i] == -2) {
                set<int>::iterator ptr = se.lower_bound(ans[2*i-1]);
                if(ptr == se.end()) {
                    bad = true;
                    break;
                }

                ans[2*i] = *ptr;
                se.erase(ptr);
            }
        }

        if(bad) {
            cout << -1 << endl;
            continue;
        } else {
            for(int i = 1; i <= 2*n; i++) {
                cout << ans[i] << " ";
            }
            cout << endl;
        }
    }
}