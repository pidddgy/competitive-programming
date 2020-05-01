// https://codeforces.com/contest/305/problem/A

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
#define cerr if(false) cerr

bool comp(string &l, string &r) {

    int lcnt = 0;
    for(char x: string("123456789")) {
        lcnt += count(l.begin(), l.end(), x);
    }

    int rcnt = 0;
    for(char x: string("123456789")) {
        rcnt += count(r.begin(), r.end(), x);
    }

    return lcnt < rcnt;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    string a[n+1];
    for(int i = 1; i <= n; i++) {
        string d;
        cin >> d;
    
        a[i] = d;
    }

    bool t1 = false;
    bool t2 = false;
    bool t3 = false;
    sort(a+1, a+n+1, comp);
    
    vector<string> ans;
    for(int i = 1; i <= n; i++) {
        string x = a[i];

        cerr << "on " << x << endl;

        if(x[x.size()-1] != '0' and t1) {
            continue;
        }
    
        if(x.size() >= 2)
        if(x[x.size()-2] != '0' and t2) {
            continue;
        }

        if(x.size() >= 3)
        if(x[x.size()-3] != '0' and t3) continue;

        ans.emplace_back(x);        

        if(x[x.size()-1] != '0') t1 = true;

        if(x.size() >= 2)
        if(x[x.size()-2] != '0') t2 = true;

        if(x.size() >= 3)
        if(x[x.size()-3] != '0') t3 = true;
    }

    cout << ans.size() << endl;
    for(string x: ans) {
        cout << x << " ";
    }
    cout<< endl;
}