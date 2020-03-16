// https://dmoj.ca/problem/dmopc18c6p2

#include <bits/stdc++.h>
#define vs vector<string>
using namespace std;

bool match(vs a, vs b) {
    for(int i = 1; i <= 4; i++) {
        if(a[i] != b[i]) return false;
    }

    return true;
}

bool iden(vs a, vs b) {
    vs x = a;
    vs y = b;

    // cout << "Comparing: " << endl;
    // for(auto c: x) cout << c << " ";
    // cout << endl;

    // for(auto c: y) cout << c << " ";
    // cout << endl;

    if(match(x, y)) return true; 

    string t = x[1];
    x[1] = x[2];
    x[2] = x[3];
    x[3] = x[4];
    x[4] = t;

    if(match(x, y)) return true; 

    t = x[1];
    x[1] = x[2];
    x[2] = x[3];
    x[3] = x[4];
    x[4] = t;

    if(match(x, y)) return true; 

    t = x[1];
    x[1] = x[2];
    x[2] = x[3];
    x[3] = x[4];
    x[4] = t;

    if(match(x, y)) return true; 
    
    return false;
}

bool mir(vs a, vs b){
    vs x = a;
    vs y = b;

   // swap(x[1], x[3]);
    cout << "Comparing: " << endl;
    for(auto c: x) cout << c << " ";
    cout << endl;

    for(auto c: y) cout << c << " ";
    cout << endl;
    // if(match(x, y)) return true;
    // swap(x[1], x[3]);

    // swap(x[2], x[4]);
    // cout << "Comparing: " << endl;
    // for(auto c: x) cout << c << " ";
    // cout << endl;

    // for(auto c: y) cout << c << " ";
    // cout << endl;
    // if(match(x, y)) return true;

    // return false;
}


int main() {
    vs a(5);
    vs b(5);
    for(int i = 1; i <= 4; i++) {
        cin >> a[i];
    }

    for(int i = 1; i <= 4; i++) {
        cin >> b[i];
    }

    if(!iden(a, b) && mir(a, b)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}