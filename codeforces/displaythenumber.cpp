// http://m2.codeforces.com/contest/1295/problem/A

#include <bits/stdc++.h>
using namespace std;
int main() {
    #define int long long
    int N;
    cin >> N;

    while(N--) {
        int a;
        cin >> a;

        string ans = "";
        while(a >= 2) {
            a -= 2;
            ans += "1";
        }

        if(a) {
            if(ans.size())
                ans.pop_back();
            ans += "7";
        }

        if(ans == "") {
            cout << 0 << endl;
            assert(false);
        } else {
            assert(ans.size() <= 998244353);
            cout << ans << endl;
        }
    }
}