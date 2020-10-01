// https://dmoj.ca/problem/usaco19decsilvp1

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
#define int long long
#define cerr if(false) cerr

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    int l = 1;
    int r = 1e12;
    int lastgood = -1;
    while(l <= r) {
        int m = (l+r)/2;

        int divis = ((m/3)+(m/5)) - (m/15);

        cerr << m << " has " << divis << endl;
        if(m-divis >= N) {
            lastgood = m;
            r = m-1;
        } else {
            l = m+1;
        }
    }

    watch(lastgood)

    while(lastgood%3 == 0 or lastgood%5 == 0) {
        lastgood--;
    }

    cout << lastgood << endl;
}