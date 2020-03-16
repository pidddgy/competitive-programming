// https://dmoj.ca/problem/mccc1s2

#include <bits/stdc++.h>
using namespace std;
int main() {

    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);
    #define endl '\n'
    int N;
    cin >> N;

    int a[N+1][N+1];

    for(int i = 1; i <= N; i++ ) {
        for(int j = 1; j <= N; j++) {
            cin >> a[i][j];
        }
    }

    vector<pair<char, int>> ans;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= 1; j++) {
            if(a[i][j] == 1) {
                // try to flip row
                bool canFlipRow = true;
                for(int k = j-1; k >= 1; k--) {
                    if(a[i][k] == 0) {
                        canFlipRow = false;
                    }
                }

                if(canFlipRow) {
                    for(int k = j; k <= N; k++) {
                        a[i][k] ^= 1;
                    }
                    ans.emplace_back(make_pair('R', i));
                    // i++;
                    // j = 1;

                } else {
                    bool canFlipColumn = true;
                    for(int k = i-1; k >= 1; k--) {
                        if(a[k][j] == 0) {
                            canFlipColumn = false;
                        }
                    }

                    if(canFlipColumn) {
                        for(int k = 1; k <= N; k++) {
                            a[k][j] ^= 1;
                        }
                        ans.emplace_back(make_pair('C', j));
                        // j++;
                        
                    }
                }


            }
        }
    }

    bool good = true;
    bool allcolumnsgood = true;

    vector<pair<char, int>> sec;

    // check all column
    for(int i = 1; i <= N; i++) {
        bool colgood = true;
        int bloop = a[1][i];
        vector<pair<char, int>> temp;
        if(bloop == 1) sec.emplace_back('C', i);

        // cout << "hi" << endl;
        
        for(int j = 1; j <= N; j++) {
            if(a[j][i] != bloop) {
                colgood = false;
            }
        } 

        if(!colgood) {
            cout << -1 << endl;
            return 0;
        }
    }

    if(allcolumnsgood) {
        cout << ans.size() + sec.size() << endl;
        for(pair<char, int> x: ans) {
            cout << x.first << " " << x.second << endl;
        }
        for(pair<char, int> x: sec) {
            cout << x.first << " " << x.second << endl;
        }
    } else {
        cout << -1 << endl;
    }
}