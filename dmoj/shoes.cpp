// https://dmoj.ca/problem/cpc19c1p0

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);


    vector<int> l;
    vector<int> r;

    for(int i = 0; i < 4; i++) {
        char a;
        cin >> a;

        if(a == 'L') l.emplace_back(i+1);
        else r.emplace_back(i+1);
    }

    cout << l[0] << " " <<  r[0] << endl;
     cout << l[1] << " " <<  r[1] << endl;




}
