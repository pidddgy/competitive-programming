// https://dmoj.ca/problem/dmopc19c5p1

#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, M;
    cin >> N >> M;

    unordered_map<string, bool> have;

    for(int i = 1; i <= N; i++) {
        string s;
        cin >> s;

        have[s] = true;
    }

    int ans = 0;
    for(int i = 1; i <= M; i++) {
        bool good = true;
        int t;
        cin >> t;

        for(int j = 1; j <= t; j++) {
            string r;
            cin >> r;

            if(!have[r]) {
                good = false;
            }
        }

        ans += good;


    }

    cout << ans << endl;
}