// https://dmoj.ca/problem/occ19g1

#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl;
using namespace std;


int main() {
    int N, k;
    cin >> N >> k;

    int s[k];
    for(int i = 0; i < k; i++) cin >> s[i];

    int p[N][k];
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < k; j++) {
            cin >> p[i][j];
        }
    }

    bool change = true;
    int ans=  0;
    bool done[N];
    for(int i = 0; i < N; i++) done[i] = false;
    while(change) {
        change = false;

        for(int i = 0; i < N; i++) {
            // watch(i)
            if(!done[i]) {
                // cout << "hi" << endl;
                bool good = true;
                for(int j = 0; j < k; j++) {
                    if(p[i][j] > s[j]) {
                        // cout << "problem " << i << " failed on skill " << j << endl;
                        good = false;
                    }
                }
                // watch(good)
                if(good) {
                    for(int j = 0; j < k; j++) {
                        s[j] += p[i][j];
                        // cout << s[j] << " ";
                    }
                    // cout << endl;
                    change = true;
                    ans++;
                    done[i] = true;
                }
            }
        }


    }

    cout << ans << endl;




}