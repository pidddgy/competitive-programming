// https://codeforces.com/contest/980/problem/B

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'

const int maxn = 105;

char inner[3][maxn];
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    for(int i = 1; i <= 2; i++) {
        for(int j = 1; j <= n; j++) {
            inner[i][j] = '.';
        }
    }
    int rem = k;

    int inLen = n-2;
    for(int i = 1; i <= 2; i++) {
        for(int j = 1; j <= inLen/2; j++) {
            if(rem >= 2) {
                inner[i][j] = '#';
                inner[i][inLen-j+1] = '#';
                rem -= 2;
            }
        }
    }

    if(rem == 1) {
        inner[1][inLen/2+1] = '#';
    } else if(rem == 2) {
        inner[1][inLen/2+1] = '#';
        inner[2][inLen/2+1] = '#';
    } else if(rem != 0) {
        cout << "NO" << endl;
    }

    cout << "YES" << endl;

    for(int i = 1; i <= n; i++) {
        cout << ".";
    }
    cout << endl;

    for(int i = 1; i <= 2; i++) {
        cout << ".";
        for(int j = 1; j <= inLen; j++) {
            cout << inner[i][j];
        }
        cout << ".";
        cout << endl;
    }

    for(int i = 1; i <= n; i++) {
        cout << ".";
    }
    cout << endl;
}