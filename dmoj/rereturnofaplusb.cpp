// https://dmoj.ca/problem/therereturnofaplusb

#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    for(unsigned i = 0; i < 1000000; i++) {
        srand(i);
        cout << rand() << "\n";
    }
}