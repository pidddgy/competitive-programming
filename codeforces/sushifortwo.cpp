// http://codeforces.com/contest/1138/problem/A

#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl;
using namespace std;
int main() {
    int n;
    cin >> n;

    vector<int> e;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    e.push_back(1);
    for(int i = 1; i < n; i++) {
        if(a[i] == a[i-1]) {
            e[e.size()-1]++;
        } else {
            e.push_back(1);
        }
    }

    int maxx = 2;
    for(int i = 1; i < e.size(); i++) {
        maxx = max( maxx, 2*min(e[i], e[i-1]) );
    }

    cout << maxx <<endl;
}
