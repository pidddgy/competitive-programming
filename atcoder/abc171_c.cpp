// https://atcoder.jp/contests/abc171/tasks/abc171_c

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define ll long long

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    ll N;
    cin >> N;

    string ans;

    while(N) {
        N--;

        ans += 'a'+(N%26);
        N /= 26;
    }

    reverse(ans.begin(), ans.end());
    
    cout << ans << endl;
}
