// https://codeforces.com/contest/1272/problem/C

#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl;
using namespace std;
#define watch(x) cout << (#x) << " is " << (x) << endl;
int main() {
    #define int long long
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    set<char> have;
    while(k--) {
        char x;
        cin >> x;

        have.emplace(x);
    }

    vector<int> b;
    string cur = "";
    for(int i = 0; i < n; i++) {
        if(have.find(s[i]) == have.end()) {
            b.emplace_back(cur.size());
            cur = "";
            continue;
        } else {
            cur.push_back(s[i]);
        } 
    }

    b.emplace_back(cur.size());



    int ans = 0;
    int c = 0;
    for(int x: b) {
        int shit = (x*(x+1))/2;
        ans += shit;
    }

    cout << ans << endl;
}