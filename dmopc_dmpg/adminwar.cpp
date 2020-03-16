// https://dmoj.ca/problem/dmpg16s1

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    int f[N];
    int x[N];

    for(auto &x: f) cin >> x;
    for(auto &x: x) cin >> x;

    sort(f, f+N);
    sort(x, x+N);

    int cur = 0;
    int fans = 0;
    for(int i = 0; i < N; i++) {
        if(f[i] > x[cur]) {
            fans++;
            cur++;
        }
    }
    
    cur = 0;
    int xans = 0;
    for(int i = 0; i < N; i++) {
        if(x[i] > f[cur]) {
            xans++;
            cur++;
        }
    }

    cout << fans << endl;
    cout << xans << endl;
}
