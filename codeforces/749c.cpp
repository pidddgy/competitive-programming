// https://codeforces.com/contest/749/problem/C

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'

const int maxn = 200500;

char a[maxn];
bool denied[maxn];
int N;


signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for(int i = 1; i <= N; i++) {
        cin >> a[i];
    }

    int totrem = 0;

    // in future

    int drem = 0, rrem = 0;
    for(int it = 1; it <= 100; it++) {
        for(int i = 1; i <= N; i++) {
            if(denied[i]) continue;

            if(a[i] == 'D') {
                if(drem) {
                    denied[i] = true;
                    drem--;
                    totrem++;
                    continue;
                } else {
                    rrem++;
                }
            } else if(a[i] == 'R') {
                if(rrem) {
                    denied[i] = true;
                    rrem--;
                    totrem++;
                    continue;
                } else {
                    drem++;
                }
            }
        }
    }

    // for(int i = 1; i <= N; i++) {
    //     cerr << denied[i] << " ";
    // }
    // cerr << endl;

    for(int i = 1; i <= N; i++) {
        if(!denied[i]) {
            cout << a[i] << endl;
            return 0;
        }
    }

}