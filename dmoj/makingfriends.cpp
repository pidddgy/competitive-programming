// https://dmoj.ca/problem/bts18p3

#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, X;
    long long total = 0;
    cin >> N >> X;

    priority_queue<int> AQT;
    for(int i = 0; i < N; i++) {
        int cute;
        cin >> cute;
        AQT.emplace(cute);
    }

    for(int i = 0; i < X; i++) {
        int aa = AQT.top();
        AQT.pop();
        total += aa;
        if(aa-1 < 0)
            AQT.emplace(0);
        else
            AQT.emplace(aa-1);
    }

    cout << total << "\n";
}