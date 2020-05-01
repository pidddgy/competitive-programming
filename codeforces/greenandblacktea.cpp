// https://codeforces.com/contest/746/problem/D

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, k, a, b;
    cin >> n >> k >> a >> b;

    string fi = "G";
    string se = "B";
    if(a < b) {
        swap(a, b);
        swap(fi, se);
    }
    
    string ans = "";
    while(a != b) {
        for(int i = 1; i <= k; i++) {
            ans += fi;
            a--;

            if(a == b) break;
        }

        if(a == b) break;
        else {
            if(b == 0) {
                cout << "NO" << endl;
                return 0;
            }
            ans += se;
            b--;
        }
    }

    if(fi[0] == ans[ans.size()-1]) {
        for(int i = 1; i <= a; i++) {
            ans += se;
            ans += fi;
        }
    } else {
        for(int i = 1; i <= a; i++) {
            ans += fi;
            ans += se;
        }
    }

    cout << ans << endl;
}