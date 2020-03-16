// https://codeforces.com/contest/1249/problem/C1

#include <bits/stdc++.h>
#define int long
#define cerr if(false) cerr
using namespace std;

set<int> good;
vector<string> S;

void f(string st = "") {
    if(st.size() == 15) {
        S.emplace_back(st);
    }

    else {
        f(st+"0");
        f(st+"1");
    }
}

signed main() {
    f();

    for(string x: S) {
        cerr << "x is " << x << endl;
        int thing = 0;
        for(int i = x.size()-1; i >= 0; i--) {
            cerr << "thing is " << x.size()-1-i << endl;
            if(x[i] == '1') {
                thing += pow(3, x.size()-1-i);
            }
        }

        good.emplace(thing);
        cerr << "emplacing " << thing << endl;
        cerr << endl;
    }

    int q;
    cin >> q;

    while(q--) {
        int n;
        cin >> n;

        cout << *good.lower_bound(n) << endl;
    }
}