// https://codeforces.com/contest/1070/problem/F

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n'
#define cerr if(false) cerr
int main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> al;
    vector<int> bo;
    vector<int> nei;

    int als = 0;
    int bos = 0;
    int sz = 0;

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        string s;
        int a;

        cin >> s >> a;

        if(s == "11") {
            ans += a;
            als++;
            bos++;
            sz++;
        } else if(s == "10") {
            al.emplace_back(a);
        } else if(s == "01") {
            bo.emplace_back(a);
        } else if(s == "00") {
            nei.emplace_back(a);      
        }
    }

    sort(al.begin(), al.end(), greater<int>());
    sort(bo.begin(), bo.end(), greater<int>());
    
    for(int i = 0; i < min(al.size(), bo.size()); i++) {
        ans += al[i] + bo[i];
        als++;
        bos++;
        sz += 2;
    }

    if(al.size() > bo.size()) {
        for(int i = min(al.size(), bo.size()); i < al.size(); i++) {
            nei.emplace_back(al[i]);
        }
    } else if (bo.size() > al.size()) {
        for(int i = min(al.size(), bo.size()); i < bo.size(); i++) {
            nei.emplace_back(bo[i]);
        }
    }

    sort(nei.begin(), nei.end(), greater<int>());
    watch(als)
    watch(bos)
    watch(sz)
    for(int i = 0; i < min((int)nei.size(), (min(als, bos)*2)-sz); i++) {
        cerr << "adding " << nei[i] << endl;
        ans += nei[i];        
    }
    


    cout << ans << endl;
}