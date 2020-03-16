// https://codeforces.com/contest/1304/problem/B

#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;

    unordered_map<string, bool> have;
    
    deque<string> ans;

    // longest single
    string lspal = "";
    for(int i = 1; i <= n; i++) {
        string x;
        cin >> x;
        string cpy = x;
        reverse(cpy.begin(), cpy.end());

        if(have[cpy]) {
            ans.push_front(x);
            ans.push_back(cpy);
        };

        if(cpy == x) {
            if(lspal.size() < x.size()) {
                lspal = x;
            }
        }

        have[x] = true;
    }

    int len = 0;
    for(string x: ans) {
        len += x.size();
    }
    if(lspal != "") {
        len += lspal.size();
    }

    cout << len << endl;

    for(int i = 0; i < ans.size()/2; i++) {
        cout << ans[i];
    }
    if(lspal != "") {
        cout << lspal;
    }

    for(int i = ans.size()/2; i < ans.size(); i++) {
        cout << ans[i];
    }
    cout << endl;
}