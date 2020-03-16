// https://codeforces.com/contest/1291/problem/A

#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl;
using namespace std;
int main() {
    int T;
    cin >> T;

    while(T--) {
        int n;
        cin >> n;

        string s;
        cin >> s;

        int out = 0;
        vector<int> ans;
        for(char x: s) {
        //     watch(x-'0')
        //     watch(x-'0' % 2)

            if((x-'0') % 2 == 1) {
                // cout << "HI" << endl;
                ans.push_back(x-'0');
                out++;
            }

            if(out == 2) break;
        }

        if(out != 2) cout << -1;
        else {
            for(int x: ans) {
                cout << x;
            }
        }

        cout << endl;

    }


}