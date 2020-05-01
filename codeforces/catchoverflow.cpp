// https://codeforces.com/contest/1175/problem/B

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int main() {
    #define int long long
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    const int lim = pow(2, 32);

    stack<int> S;

    int l;
    cin >> l;

    S.push(1);
    int tot = 0;
    while(l--) {
        string type;
        cin >> type;

        if(type == "for") {
            int n;
            cin >> n;

            S.push(min(lim, S.top()*n));
        } else if(type == "end") {
            S.pop();
        } else if(type == "add") {
            tot += S.top();
        }
    }

    if(tot >= lim) {
        cout << "OVERFLOW!!!" << endl;
    } else {
        cout << tot << endl;
    }
}