// https://codeforces.com/contest/367/problem/A

#include <bits/stdc++.h>
#define maxssize 100500
using namespace std;

int psa[5][maxssize];

int main() {
    string s;
    cin >> s;
    int N = s.size();

    s = "."+s;
    for(int i = 1; i <= N; i++) {
        char x = s[i];

        psa[x-'x'][i] ++;
    }

    for(int x = 0; x <= 2; x++) {
        for(int i = 1; i <= N; i++) {
            psa[x][i] += psa[x][i-1];
        }    
    }

    int M;
    cin >> M;

    for(int query = 1; query <= M; query++) {
        int l, r;
        cin >> l >> r;

        if(r-l+1 < 3) {
            cout << "YES" << endl;
            continue;
        }

        int xc = psa[0][r] - psa[0][l-1];
        int yc = psa[1][r] - psa[1][l-1];
        int zc = psa[2][r] - psa[2][l-1];

        if(max({xc, yc, zc}) - min({xc, yc, zc}) <= 1) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}