// https://codeforces.com/contest/1077/problem/D

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
#define cerr if(false) cerr
#define pii pair<int, int>
#define fi first
#define se second
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    map<int, int> cnt;
    for(int i = 1; i <= n; i++) {
        int _;
        cin >> _;

        cnt[_]++;
    }

    int l = 1;
    int r = 200500;
    int lastgood = -1;

    while(l <= r) {
        // watch(l)
        // watch(r)
        // only take elements with count >= m
        int m = (l+r)/2;
        cerr << "trying " << m << endl;
        priority_queue<int> cntsorted;
        for(pii x: cnt) {
            cerr << "emplacing " << x.se << endl;
            cntsorted.emplace(x.se);
        }

        int have = 0;

        while(have < k) {
            if(cntsorted.empty()) break;
            have += cntsorted.top() / m;
            cntsorted.pop();
        }

        if(have >= k) {
            lastgood = m;
            l = m+1;
        } else {
            r = m-1;
        }
    }

    watch(lastgood)
    priority_queue<pii> cntsorted;
    for(pii x: cnt) {
        cerr << "emplacing " << x.se << endl;
        cntsorted.emplace(x.se, x.fi);
    }
    
    int have = 0;

    while(have < k) {
        for(int i = 0; i < cntsorted.top().fi/lastgood; i++) {
            cout << cntsorted.top().se << " ";
            have++;
            if(have == k) break;
        }
        if(have == k) break;

        cntsorted.pop();
    }
    cout << endl;


}