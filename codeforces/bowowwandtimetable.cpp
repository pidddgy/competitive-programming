// http://codeforces.com/contest/1204/problem/0

#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl;
using namespace std;
int main() {
    #define int long long
    string s;
    cin >> s;
    int a = stoi(s, nullptr, 2);

    int i = 0;
    int ans = 0;
    for(; i <= 10000; i++) {
        if(pow(4, i) < a) {
            ans++;
        } else {
            break;
        }
    }

    cout << ans << endl;
}
