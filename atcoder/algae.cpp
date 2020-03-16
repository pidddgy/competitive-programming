// https://atcoder.jp/contests/abc127/tasks/abc127_b

#include <bits/stdc++.h>
using namespace std;
int main() {
    int r, d, prev;
    cin >> r >> d >> prev;

    
    for(int i = 1; i <= 10; i++) {
        cout << r*prev-d << endl;
        prev = r*prev-d;
    }

    
}
