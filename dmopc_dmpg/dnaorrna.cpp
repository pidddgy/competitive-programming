// https://dmoj.ca/problem/dmopc18c6p1

#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl;
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int a; cin >> a;
    cin.ignore();

    string s;
    getline(cin, s);

    bool d = true;
    bool r = true;
    bool n = true;
    for(char a: s) {
        if(a != 'A' && a != 'C' && a != 'G' && a != 'T' && a != 'U') n = true;
        if(a != 'A' && a != 'C' && a != 'G' && a != 'T') d = false;
        if(a != 'A' && a != 'C' && a != 'G' && a != 'U') r = false;
    }



    if(r && d) {
        cout << "both";
    } else if(r) {
        cout << "RNA";
    } else if(d) {
        cout << "DNA";
    } else if(n) {
        cout << "neither";
    }
    cout << endl;


}
