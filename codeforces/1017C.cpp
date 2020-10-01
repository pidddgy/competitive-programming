// https://codeforces.com/contest/1017/problem/C

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define cerr if(false) cerr

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int best = INT_MAX, bestlen = -1;
    for(int bl = 1; bl <= n; bl++) {
        cerr << "trying " << bl << endl;
        cerr << "inc is " << bl+(n%bl) << endl;
        cerr << "dec is " << n/bl << endl;
        int num = bl + ((n+bl-1)/bl);

        if(num <= best) {
            best = num;
            bestlen = bl;
        }
        cerr << endl;
    }
    cerr << "using block size " << bestlen << endl;
    watch(best)
    deque<int> cur;
    for(int i = 1; i <= n; i++) {
        cur.emplace_back(i);

        if(cur.size() == bestlen) {
            while(cur.size()) {
                cout << cur.back() << " ";
                cur.pop_back();
            }
        }
    }

    while(cur.size()) {
        cout << cur.back() << " ";
        cur.pop_back();
    }

    cout << endl;   
}