// https://codeforces.com/problemset/problem/867/A

#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;

    int s = 0;
    int f = 0;

    char last;
    cin >> last;
    for(int i = 1; i <= N-1; i++) {
        char c;
        cin >> c;

        if(last == 'S' and c == 'F') {
            s++;
        } else if(last == 'F' and c == 'S') {
            f++;
        }
        last = c;
    }

    if(s > f) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

}