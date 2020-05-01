// https://codeforces.com/contest/920/problem/C

#include <bits/stdc++.h>
using namespace std;
int main() {
    #define int long long
    int N;
    cin >> N;

    int a[N+1];
    for(int i = 1; i <= N; i++) cin >> a[i];

    int apsa[N+1];
    apsa[0] = 0;
    for(int i = 1; i <= N; i++) {
        apsa[i] = a[i];
        apsa[i] += apsa[i-1];
    }

    // lol subtraction is confusing so here we are
    int trngpsa[N+1];
    trngpsa[0] = 0;
    for(int i = 1; i <= N; i++) {
        trngpsa[i] = (i*(i+1))/ 2;
    }

    bool swappable[N+1];
    for(int i = 1; i <= N; i++) swappable[i] = false;
    for(int i = 1; i <= N-1; i++) {
        char x;
        cin >> x;

        if(x == '1') {
            swappable[i] = true;
        }
    }

    int last = -1;
    for(int i = 1; i <= N; i++) {
        if(!swappable[i]) {
            if(last != -1) {
                if(apsa[i] - apsa[last-1] != trngpsa[i] - trngpsa[last-1]) {
                    cout << "NO" << endl;
                    return 0;
                } else {
                    last = -1;
                }
            } else if(a[i] != i) {
                cout << "NO" << endl;
                return 0;
            }
        } else {
            if(last == -1) {
                last = i;
            }
        }
    }

    cout << "YES" << endl;
}