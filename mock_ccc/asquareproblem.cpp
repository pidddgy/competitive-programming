// https://dmoj.ca/problem/nccc1j4s2

#include <bits/stdc++.h>
#define endl '\n'
#pragma GCC optimize "Ofast"

using namespace std;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    cin.ignore();
    int aqt[n][n];

    for(int i = 0; i < n; i++) {
        string a;
        getline(cin, a);
        for(unsigned j = 0; j < a.size(); j++)
            if(isdigit(a[j]))
                aqt[i][j] = a[j]-'0';
            else
                aqt[i][j] = a[j]-55;
    }

    string ret = "Latin";
    // Check each row
    for(int r = 0; r < n; r++) {
        set<int> S;
        for(int c = 0; c < n; c++)
            S.insert(aqt[r][c]);
        if(S.size() != n)
            ret = "No";
    }

    // Check each column
    for(int r = 0; r < n; r++) {
        set<int> S;
        for(int c = 0; c < n; c++)
            S.insert(aqt[c][r]);
        if(S.size() != n)
            ret = "No";
    }

    bool good = false;
    if(ret == "Latin") {
        good = true;

        // Check top
        int prev = aqt[0][0];
        for(int i = 1; i < n; i++) {
            if(aqt[0][i] < prev) {
                good = false;
            }
            prev = aqt[0][i];
        }

        // Check left
        prev = aqt[0][0];
        for(int i = 1; i < n; i++) {
            if(aqt[i][0] < prev)
                good = false;
            prev = aqt[0][i];
        }
    }
    if(good) 
        ret = "Reduced";
    cout << ret << endl;
}
