// https://dmoj.ca/problem/wac3p3

// orz chadliam

#include <bits/stdc++.h>
using namespace std;
int main() {
    #define int long long
    string S;
    cin >> S;

    int N = S.size();

    S = "."+S;

    int M;
    cin >> M;

    string C[M+1];
    int P[M+1];

    for(int i = 1; i <= M; i++) {
        cin >> C[i] >> P[i];
    }

    int cur = 1;
    int ans = 0;

    while(cur <= N) {
        // cout << "hi" << endl;
        int ma = 0;
        int points = 0;
        for(int i = 1; i <= M; i++) {
            bool isequal = true;

            // cout << "on " << cur << endl;
            if(cur+C[i].size() <= N+1) {
                for(int j = 0; j < C[i].size(); j++) {
                    // cout << "comparing C at ind " << j << " to S at ind " << cur+j << endl;
                    if(S[cur+j] != C[i][j]) {
                        // cout << "failed on " << i+j << endl;
                        isequal = false;
                        break;
                    }
                }
            } else {
                isequal = false;
            }

            if(isequal) {
                // cout << "valid" << endl;
                int shit = C[i].length();
                if(shit > ma) {
                    ma = shit;
                    // cout << "setting points to " << P[i] << endl;
                    points = P[i];
                }   
            }

        }

        // cout << "on " << cur << endl;
        // cout << "adding " << points << endl;
        if(ma == 0) {
            cur++;            
        } else {
            cur += ma;
        }

        ans += points;

        // cout << endl;


    }

    cout << ans+N << endl;

}