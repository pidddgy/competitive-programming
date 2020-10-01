// https://codeforces.com/contest/1384/problem/0

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n'
#define int long long
#define all(x) (x).begin(), (x).end()

const string alpha = "abcdefghijklmnopqrstuvwxyz";
void solve() {
    int n;
    cin >> n;
    
    int a[n];

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<string> ans;

    string init = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
    ans.emplace_back(init);

    for(int i = 0; i < n; i++) {
        string emp;

        for(int j = 0; j < a[i]; j++) {
            emp += ans.back()[j];
        }

        for(char x: alpha) {
            if(x != ans.back()[a[i]]) {
                while(emp.size() < 200) {
                    emp += x;
                }
                break;
            }
        }
        ans.emplace_back(emp);
    }

    for(string x: ans) {
        cout << x << endl;
    }
}
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        solve();
    }
}
