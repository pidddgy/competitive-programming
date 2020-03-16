// https://dmoj.ca/problem/dmopc19c5p3

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
int main() {
    int H, V;
    cin >> H >> V;
    H--;
    V--;

    int ans = 0;
    for(int i = 1; i <= H; i++) {
        for(int j = 1; j <= V; j++) {
            // watch(i)
            // watch(j)
            unordered_map<int, unordered_map<int, bool>> used;
            for(int k = 1; k <= H-i; k++) {
                for(int l = 1; l <= V-j; l++) {
                    if(used[k][l]) continue;

                    watch(i)
                    watch(j)
                    watch(k)
                    watch(l)

                    if(k % 2 == 1 and l % 2 == 1) {
                        ans++;
                    }

                    ans++;

                    cerr << endl;
                    used[k][l] = true;
                }
            }
        }   
    }

    cout << ans << endl;
}