// https://codeforces.com/contest/246/problem/C

#include <bits/stdc++.h>
#define pvi pair<vector<int>, int>
#define fi first
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define se second
using namespace std;
#define endl '\n'
int main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    int a[n+1];
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    unordered_map<int, bool> used;
    vector<pvi> possibilities;
    vector<int> init = {};
    possibilities.emplace_back(init, 0);

    for(int i = 1; i <= n; i++) {
        vector<pvi> toEmplace;
        for(pvi x: possibilities) {
            if(!used[x.se+a[i]]) {

                vector<int> f = x.fi;
                int s = x.se;

                f.emplace_back(a[i]);
                s += a[i];

                toEmplace.emplace_back(f, s);

                used[x.se+a[i]] = true;
            }
        }
        for(pvi x: toEmplace) {
            possibilities.emplace_back(x);
        }

        if(possibilities.size() > k+5) break;
    }
    int sent = 0;
    for(pvi x: possibilities) {
        if(x.se == 0) continue;
        cout << x.fi.size() << " ";

        for(int y: x.fi) {
            cout << y << " ";
        }

        cout << endl;
        sent++;

        if(sent == k) break;
    }
}