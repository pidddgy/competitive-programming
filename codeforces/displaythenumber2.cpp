// https://codeforces.com/contest/1295/problem/A

#include <bits/stdc++.h>
using namespace std;
int main() {
    #define int long long
    int T;
    cin >> T;

    for(int i = 0; i < T; i++) {
        int n;
        cin >> n;

        vector<char> ans;

        if(n % 2 == 1) {
            ans.emplace_back('7');
        }
        for(int j = 0; j < n/2; j++) {
            ans.emplace_back('1');
        }

        if(n % 2 == 1) {
            ans.pop_back();
        }

        for(char x: ans) {
            cout << x;
        }

        cout << endl;
    }
}