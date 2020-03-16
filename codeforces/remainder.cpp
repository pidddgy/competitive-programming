// http://codeforces.com/contest/1165/problem/A

#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, x, y;
    cin >> n >> x >> y;

    string s;
    cin >> s;

    s = "."+s;
    int ans = 0;

    for(int i = n-x+1; i <= n-y-1; i++) {
        if(s[i] == '1') {
            s[i] = '0';
            ans++;
        }
    }

    if(s[n-y] == '0') {
        s[n-x] = '1';
        ans++;
    }

    for(int i = n-y+1; i <= n; i++) {
        if(s[i] == '1') {
            s[i] = '0';
            ans++;
        }
    }
    cout << ans<<endl;
    // cout << s << endl;
}
