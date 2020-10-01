// https://codeforces.com/contest/753/problem/B

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;

signed main() {

    int non = -1;
    for(int i = 0; i <= 9; i++) {
        for(int j = 1; j <= 4; j++) {
            cout << i;
        }

        cout << endl;

        int a, b;
        cin >> a >> b;

        if(a == 0 and b == 0) {
            non = i;
            break;
        }
    }

    // print i nons

    vector<int> ans;
    for(int i = 0; i <= 3; i++) {
        for(int j = 0; j <= 9; j++) {
            for(int k = 0; k < i; k++) {
                cout << non;
            }
            cout << j;
            for(int k = 0; k < 4-i-1; k++) {
                cout << non;
            }
            cout << endl;
            cout.flush();

            int a, b;
            cin >> a >> b;

            if(a == 1) {
                ans.emplace_back(j);
                break;
            }
        }
    }

    for(int x: ans) {
        cout << x;
    }
    cout << endl;
}
