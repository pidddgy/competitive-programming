// https://dmoj.ca/problem/ccc12s5

#include <bits/stdc++.h>
#define endl '\n'
#pragma GCC optimize "Ofast"

using namespace std;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int R, C, K;
    long long AQT_IS_ADORABLE_CUTE_AND_SMART[26][26];
    bool isCat[26][26];

    for(int i = 0; i < 26; i++)
        for(int j = 0; j < 26; j++) { 
            AQT_IS_ADORABLE_CUTE_AND_SMART[i][j] = 0;
            isCat[i][j] = false;
        }

    cin >> R >> C >> K;
    for(int i = 0; i < K; i++) {
        int a, b;
        cin >> a >> b;
        isCat[a-1][b-1] = true;
    }

    AQT_IS_ADORABLE_CUTE_AND_SMART[0][0] = 1;
    for(int i = 0; i < R; i++) 
        for(int j = 0; j < C; j++)
            if(!isCat[i][j] && AQT_IS_ADORABLE_CUTE_AND_SMART[i][j] == 0) {
                int aqt = 0;
                if(i-1 >= 0)
                    aqt += AQT_IS_ADORABLE_CUTE_AND_SMART[i-1][j];
                if(j-1 >= 0)
                    aqt += AQT_IS_ADORABLE_CUTE_AND_SMART[i][j-1];
                AQT_IS_ADORABLE_CUTE_AND_SMART[i][j] = aqt;
            }

    cout << AQT_IS_ADORABLE_CUTE_AND_SMART[R-1][C-1] << endl;
}
