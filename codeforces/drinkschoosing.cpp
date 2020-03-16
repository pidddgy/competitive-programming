// http://codeforces.com/contest/1195/problem/0

#include <bits/stdc++.h>
using namespace std;
int cnt[1005];
int main() {
    int n, k;
    cin >> n >> k;

    int budget = ceil((double)n / 2.0);

    //cout << budget << endl;

    for(int i = 1; i <= n; i++) {
        int a;
        cin >> a;

        cnt[a]++;
    }

    int fav = 0;

    for(int i = 1; i <= k; i++) {
        while(cnt[i] >= 2 && budget > 0) {
            cnt[i] -= 2;
            budget--;
            fav += 2;
        }
    }

    for(int i = 1; i <= k; i++) {
        while(cnt[i] && budget) {
            cnt[i] --;
            budget--;
            fav += 1;
        }
    }

    cout << fav << endl;



    
}