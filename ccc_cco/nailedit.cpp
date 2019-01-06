// https://dmoj.ca/problem/ccc17s3

#include <bits/stdc++.h>
using namespace std;
int main() {
    int N; cin >> N;
    int wood[2002]; // elem i is how many wood with length i we have <3
    for(int i = 0; i < 2002; i++) wood[i] = 0;
    int sums[4004]; for(int i = 0; i < 4004; i++) sums[i] = 0;
    for(int i = 0; i < N; i++) {
        int aqt;
        cin >> aqt;
        wood[aqt]++;
    }

    for(int i = 1; i < 2002; i++) {
        if(wood[i] > 0) {
            for(int j = i; j < 2002; j++) {
                if(i == j) 
                    sums[i+j] += wood[i]/2;
                else if (wood[j] > 0)
                    sums[i+j] += min(wood[i], wood[j]);
            }
        }
    }

    int ans1 = 0;
    int ans2 = 0;
    for(int i = 0; i < 4004; i++) {
        if(sums[i] > ans1) {
            ans1=sums[i];
            ans2 = 1;
        } else if(sums[i] == ans1) ans2++;
    }
    cout << ans1 << " " << ans2 << endl;
}
