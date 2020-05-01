// https://codeforces.com/contest/1151/problem/B

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
const int maxn = 505;
int n, m;
int a[maxn][maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            int _;
            cin >> _;

            a[i][j] = _;
        }
    }

    for(int bit = 0; bit <= 9; bit++) {
        int force = 0;
        int opt = 0;
        for(int i = 1; i <= n; i++) {
            bool hasbit = false, hasnon = false;

            for(int j = 1; j <= m; j++) {
                int comp = 1<<bit;

                if(a[i][j] & comp) {
                    hasbit = true;
                } else {
                    hasnon = true;
                }
            }

            if(hasbit and !hasnon) {
                force++;
            } else if(hasbit and hasnon) {
                opt++;
            }
        }


        if(((force%2)==1)) {
            vector<int> ans;
            for(int i = 1; i <= n; i++) {
                int bitind = -1, nonind = -1;

                for(int j = 1; j <= m; j++) {
                    int comp = 1<<bit;

                    if(a[i][j] & comp) {
                        bitind = j;
                    } else {
                        nonind = j;
                    }
                }

                if(bitind != -1 and nonind == -1) {
                    ans.emplace_back(bitind);
                } else {
                    ans.emplace_back(nonind);
                }
            }

            cout << "TAK" << endl;
            for(int x: ans) {
                cout << x << " ";
            }
            cout << endl;
            return 0;
        } else if((force%2==0) and opt) {
            vector<int> ans;
            bool tookopt = false;
            for(int i = 1; i <= n; i++) {
                int bitind = -1, nonind = -1;

                for(int j = 1; j <= m; j++) {
                    int comp = 1<<bit;

                    if(a[i][j] & comp) {
                        bitind = j;
                    } else {
                        nonind = j;
                    }
                }

                if(bitind != -1 and nonind != -1) {
                    if(!tookopt) {
                        ans.emplace_back(bitind);
                        tookopt = true;
                    } else {
                        ans.emplace_back(nonind);
                    }
                } else if(bitind != -1 and nonind == -1) {
                    ans.emplace_back(bitind);
                } else if(bitind == -1 and nonind != -1) {
                    ans.emplace_back(nonind);
                } 
            }

            cout << "TAK" << endl;
            for(int x: ans) {
                cout << x << " ";
            }
            cout << endl;
            return 0;
        }
    }

    cout << "NIE" << endl;
}