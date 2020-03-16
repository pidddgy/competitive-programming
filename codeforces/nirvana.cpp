// http://codeforces.com/problemset/problem/1143/B

#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl;
using namespace std;
int main() {
    string s; cin >> s;

    int N = s.size();
    s = "." +s;

    int ans = 1;
    for(int i = 1; i <= N; i++) {
        ans *= s[i]-'0';
    }

    for(int i = 1; i <= N-1; i++) {
        if(s[i] == '0') continue;
        string cpy = s;

        cpy[i]--;
        for(int j = i+1; j <= N; j++) {
            cpy[j] = '9';
        }
        //watch(cpy)

        int cur = 1;
        for(int j = 1; j <= N; j++) {
            if(cpy[j] == '0') continue;
            cur *= cpy[j]-'0';
        }

        ans = max(ans, cur);
    }

    cout << ans << endl;
}