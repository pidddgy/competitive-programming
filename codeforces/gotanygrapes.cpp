// http://codeforces.com/contest/1114/problem/A

#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
int main() {
    int x, y, z;
    int a, b, c;
    cin >> x >> y >> z >> a >> b >> c;

    if(a + b + c < x + y + z) {
        cout << "NO" << endl;
    } else {
        int andr = 0;
        int dmit = 0;
        int mich = 0;

        while(andr < x && a > 0) {
            a--;
            andr++;
        } 

        while(dmit < y && a > 0) {
            a--;
            dmit++;
        }

        while(dmit < y && b > 0) {
            b--;
            dmit++;
        }

        while(mich < z && a > 0) {
            a--;
            mich++;
        }
        while(mich < z && b > 0) {
            b--;
            mich++;
        }
        while(mich < z && c > 0) {
            c--;
            mich++;
        }


        if(a >= 0 && b >= 0 && c >= 0 && andr == x && dmit == y && mich == z) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }

    }
}
