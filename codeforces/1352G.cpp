// https://codeforces.com/contest/1352/problem/G

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 

const int maxt = 105;

vector<int> res[maxt];
map<int, set<int>> queries;
set<int> done;
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    for(int i = 1; i <= T; i++) {
        int x;
        cin >> x;

        queries[x].emplace(i);
    }

    for(int i = 0; i <= 46; i++) {
        for(int j = 0; j <= 46; j++) {
            for(int k = 0; k <= 46; k++) {
                for(int l = 0; l <= 46; l++) {
                    int num = 4*i + 5*j + 6*k + 7*l;
                    
                    if(queries.count(num)) {
                        if(done.count(num)) continue;
                        done.emplace(num);
                        vector<int> ans;

                        int cur = 1;
                        for(int ii = 1; ii <= i; ii++) {
                            ans.emplace_back(cur+1);
                            ans.emplace_back(cur+3);
                            ans.emplace_back(cur);
                            ans.emplace_back(cur+2);
                            cur += 4;
                        }

                        for(int jj = 1; jj <= j; jj++) {
                            ans.emplace_back(cur);
                            ans.emplace_back(cur+3);
                            ans.emplace_back(cur+1);
                            ans.emplace_back(cur+4);
                            ans.emplace_back(cur+2);
                            cur += 5;
                        }

                        for(int kk = 1; kk <= k; kk++) {
                            ans.emplace_back(cur);
                            ans.emplace_back(cur+3);
                            ans.emplace_back(cur+1);
                            ans.emplace_back(cur+5);
                            ans.emplace_back(cur+2);
                            ans.emplace_back(cur+4);

                            cur += 6;
                        }

                        for(int ll = 1; ll <= l; ll++) {
                            ans.emplace_back(cur);
                            ans.emplace_back(cur+4);
                            ans.emplace_back(cur+1);
                            ans.emplace_back(cur+5);
                            ans.emplace_back(cur+2);
                            ans.emplace_back(cur+6);
                            ans.emplace_back(cur+3);
                            cur += 7;
                        }

                        for(int ind: queries[num]) {
                            res[ind] = ans;
                        }
                    }
                }
            }
        }
    }

    for(int i = 1; i <= T; i++) {
        if(res[i].empty()) {
            cout << -1 << endl;
        } else {
            for(int x: res[i]) {
                cout << x << " ";
            }
            cout << endl;
        }
    }
}