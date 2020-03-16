// https://atcoder.jp/contests/abc154/tasks/abc154_c

#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;


    set<int> have;
    for(int i = 1; i <= N; i++) {
        int x;
        cin >> x;

        if(have.find(x) != have.end()) {
            cout << "NO" << endl;
            return 0;
        } else {
            have.emplace(x);
        }
    }

    cout << "YES" << endl;


}