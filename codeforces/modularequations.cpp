// https://codeforces.com/contest/495/problem/B

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    #define int long long
    int a, b;
    cin >> a >> b;

    if(a == b) {
        cout << "infinity" << endl;
        return 0;
    }

    int c = a-b;

    set<int> S;
    for(int i = 1; i <= min(c, (int)sqrt(c)+5); i++) {
        if(c % i == 0) {
            if(i > b) {
                S.emplace(i);
            }
            if((c/i) > b) {
                S.emplace(c/i);
            }
        }
    }

    cout << S.size() << endl;
}
