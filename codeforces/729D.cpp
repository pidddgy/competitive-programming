// https://codeforces.com/contest/729/problem/D

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define pii pair<int, int>
#define fi first
#define se second

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, a, b, k;
    cin >> n >> a >> b >> k;

    string s;
    cin >> s;

    vector<int> inds;
    for(int i = 0; i < n; i++) {
        if(s[i] == '1') continue;
        int j = i;

        while(j+1 < n and s[j+1] == '0') j++;

        for(int k = i+b-1; k <= j; k += b) {
            inds.emplace_back(k+1);
        }

        i = j;
    }

    int take = inds.size()-a+1;

    cout << take << endl;
    for(int i = 0; i < take; i++) {
        cout << inds[i] << " ";
    }
    cout << endl;
}
