// https://codeforces.com/contest/581/problem/D

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 

int x[5], y[5];
char ans[500][500];

void clear() {
    for(int i = 0; i < 500; i++) {
        for(int j = 0; j < 500; j++) {
            ans[i][j] = '?';
        }
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int sum = 0;
    for(int i = 0; i < 3; i++) {
        cin >> x[i] >> y[i];
        sum += x[i]*y[i];
    }

    int rt = sqrt(sum);

    if(rt*rt != sum) {
        cout << -1 << endl;
        return 0;
    }


    string order = "ABC";
    do {
        for(int mask = 0; mask <= 7; mask++) {
            clear();
            bool haveAns = true;
            for(int ind = 0; ind < 3; ind++) {
                char chr = order[ind];
                
                // horizontal, vertical
                int h = x[chr-'A'];
                int v = y[chr-'A'];
                if((1<<ind)&mask) {
                    swap(h, v);
                }

                bool found = false;
                for(int i = 0; i+h-1 < rt; i++) {
                    for(int j = 0; j+v-1 < rt; j++) {
                        bool ok = true;
                        for(int k = 0; k < h; k++) {
                            for(int l = 0; l < v; l++) {
                                if(ans[i+k][j+l] != '?') {
                                    ok = false;
                                }
                            }
                        }

                        if(ok) {
                            found = true;
                            for(int k = 0; k < h; k++) {
                                for(int l = 0; l < v; l++) {
                                    ans[i+k][j+l] = chr;
                                }
                            }
                        }

                        if(found) break;
                    }
                    if(found) break;
                }
                if(!found) haveAns = false;
            }

            if(haveAns) {
                cout << rt << endl;
                for(int i = 0; i < rt; i++) {
                    for(int j = 0; j < rt; j++) {
                        cout << ans[i][j];
                    }
                    cout << endl;
                }
                return 0;
            }
        }
    }
    while(next_permutation(order.begin(), order.end()));

    cout << -1 << endl;
}