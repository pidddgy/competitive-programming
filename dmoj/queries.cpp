// https://dmoj.ca/problem/dmopc16c2p3

#include <bits/stdc++.h>
using namespace std;
void solve() {
    int N, M;
    cin >> N >> M;
    int a = 0;
    int b = 0;
    for(int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;

        a = max(a, x);
        b = max(b, y);
    }

    if(a+b > N) {
        cout << -1 << endl;
        return;
    }

    for(int i = 0; i < a; i++)
        cout<<"a";
    for(int i = 0; i < N-a; i++)
        cout<<"b";
    cout<<endl;
}

int main() {
    int T;
    cin >> T;
    for(int i = 0; i < T; i++) {
        solve();
    }
}