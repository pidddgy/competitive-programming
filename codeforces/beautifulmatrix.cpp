// http://codeforces.com/contest/263/problem/A

#include <bits/stdc++.h>
using namespace std;
int main() {
    int r, c;

    for(int i = 1; i <= 5; i++) {
        for(int j = 1; j <= 5; j++) {
            int aa;
            cin >> aa;
            if(aa == 1) {
                r = i;
                c = j;
            }
        }
    }

    cout << abs(r-3) + abs(c-3) << endl;
}
