// http://codeforces.com/contest/1100/problem/B
// PLS NO HACK ME OR I WILL BE SAD
#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    int aa= 0;
    cin >> n >> m;

    int have[n];
    int count[n]; 
    
    for(int i = 0; i < n; i++) {
        count[i] = 0;
        have[i] = false;
    }

    int sum = 0;

    for(int i = 0; i < m; i++) {
        int P; cin >> P;
        count[P-1]++;

        if(!have[P-1]) {
            sum++;
            have[P-1] = true;
        }

        if(sum == n) {
            cout << 1;
            aa++;

            for(int i = 0; i < n; i++) {
                if(count[i] == aa) {
                    have[i] = false;
                    sum--;
                }
            }
            
        } else cout << 0;
            
    }

    cout << endl;
}