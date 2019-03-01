// https://dmoj.ca/problem/nccc7j1

#include <bits/stdc++.h>
using namespace std;
int main() {
    int a = 0;
    for(int i = 0; i < 5; i++) {
        char b;
        cin >> b;
        if(b == 'P') a++;
    }
    cout << a << endl;
}