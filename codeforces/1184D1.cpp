// https://codeforces.com/contest/1184/problem/D1

#include <bits/stdc++.h>
#define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;

#define endl '\n'

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, k, m, t;
    cin >> n >> k >> m >> t;
    k--;
    deque<int> a(n);
    for(int i = 0; i < n; i++) {
        a[i] = 0;
    }
    a[k] = 1;
    
     for(int i = 0; i < a.size(); i++) {
            cerr << a[i] << " ";
        }
        cerr << endl;
    while(t--) {
        int type, i;
        cin >> type >> i;

        if(type == 1) {
            a.insert(a.begin()+(i-1), 0);
        } else {
            if(a.size()==1) continue;

            const int asz = a.size();
            if(k <= i-1) {
                for(int j = 0; j < (asz-i); j++) a.pop_back();
            } else {
                for(int j = 0; j < i; j++) a.pop_front();
            }
        }

        for(int i = 0; i < a.size(); i++) {
            cerr << a[i] << " ";
        }
        cerr << endl;
        
        for(int i = 0; i < a.size(); i++) {
            if(a[i] == 1) {
                k = i;
                break;
            }
        }

        cout << a.size() << " " << k+1 << endl;
        cerr << endl;
    }
}

/*
5 2 10 5
1 1
1 1
1 1
0 5
0 3
*/