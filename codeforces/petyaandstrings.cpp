// http://codeforces.com/contest/112/problem/A

#include <bits/stdc++.h>
using namespace std;
int main() {
    string a; 
    string b;
    cin >> a >> b;

    for(auto& x: a) {
        if(isupper(x)) x = tolower(x);
    }
    for(auto& x: b) {
        if(isupper(x)) x = tolower(x);
    }


    if(a < b) cout << -1 << endl;
    else if(b < a) cout << 1 << endl;
    else cout << 0 << endl;
}
