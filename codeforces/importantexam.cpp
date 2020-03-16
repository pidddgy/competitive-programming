// http://codeforces.com/contest/1201/problem/A

#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl;
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;

    map<char, int> a[m+1];

    for(int i = 1; i <= n; i++) {
        string s; cin >> s;
        s = "."+s;

        for(int j = 1; j <= m; j++) {
            a[j][s[j]]++;
        }
    }

    int values[m+1];
    for(int i = 1; i <= m; i++) {
        cin >> values[i];
    }
    
    int ans = 0;
    for(int i = 1; i <= m; i++) {
        int ma = 0;
        for(char x: "ABCDE") {
            ma = max(ma, a[i][x]);
        }

        ans += ma*values[i];
    }

    cout << ans << endl;
}