// https://codeforces.com/problemsets/acmsguru/problem/99999/358

#include <bits/stdc++.h>
using namespace std;
int main() {
    int meds[3];

    for(int i = 0; i < 3; i++) {
        int m[3];
        cin >> m[0] >> m[1] >> m[2];

        sort(m, m+3);

        meds[i] = m[1];
    }

    sort(meds, meds+3);

    cout << meds[1] << endl;
}