// http://codeforces.com/problemset/problem/1144/C

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int a[200420];

int main() {
    int maxval = 200420;

    int N;
    cin >> N;

    for(int i = 1; i <= N; i++) {
        int b; cin >> b;
        a[b]++;
        if(a[b] > 2) {
            cout << "NO" << endl;
            return 0;
        }
    }

    vector<int> inc;
    vector<int> dec;
    for(int i = 0; i <= maxval; i++) {
        if(a[i]) {
            inc.push_back(i);
            a[i]--;
        }
    }

    for(int i = maxval; i >= 0; i--) {
        if(a[i] != 0) {
            dec.push_back(i);
            a[i]--;
        }
    }

    cout << "YES" << endl;
    cout << inc.size() << endl;
    for(int x: inc) cout << x << " ";
    cout << endl;
    
    cout << dec.size() << endl;
    for(int x: dec) cout << x << " ";
    cout << endl;
}
