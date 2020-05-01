// https://codeforces.com/contest/724/problem/B

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    
    string ans = "NO";

    int a[n+1][m+1];
    for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) cin >> a[i][j];

    for(int i = 1; i <= m; i++) {
        for(int j = i; j <= m; j++) {
            int cpy[n+1][m+1];
            for(int k = 1; k <= n; k++) {
                for(int l = 1; l <= m; l++) {
                    cpy[k][l] = a[k][l];
                    if(l == i) cpy[k][l] = a[k][j];
                    if(l == j) cpy[k][l] = a[k][i];
                }
            }

            bool works = true;
            for(int k = 1; k <= n; k++) {
                vector<int> wrong;
                for(int l = 1; l <= m; l++) {
                    if(cpy[k][l] != l) {
                        wrong.emplace_back(l);
                    }
                }
                
                bool good = true;
                if(wrong.size() == 2) {
                    if(cpy[k][wrong[0]] == cpy[k][wrong[1]]) {
                        good = false;
                    }
                } else good = (wrong.size() < 2);

                if(!good) works = false;
            }

            if(works) {
                // cerr << "use columns " << i << " " << j << endl;
                ans = "YES";
            }
        }
    }
    cout << ans << endl;
}